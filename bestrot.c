#include <admesh/stl.h>
#include <stdio.h>

int main( char * fileOne,  char * fileTwo ){
    stl_file stl;
    char * filename = fileOne;
    double x = 999999;
    double y = 999999;
    int rotate = 0;
    stl_open(&stl, filename);
    stl_exit_on_error(&stl);
    for(int i = 0; i < 180; i+=5 )
    {
        if ((stl.stats.size.x * stl.stats.size.y) < (x * y)){
            x = stl.stats.size.x;
            y = stl.stats.size.y;
            rotate = i;
        }
        stl_rotate_z(&stl, 5);
        //printf("best volume  %lf\n", x*y);    
    }
    printf("rotate by %lld\n", rotate);
    stl_rotate_z(&stl, rotate);
    stl_write_ascii(&stl, fileTwo, "hellskull_rotated" );
    stl_close(&stl);
    return 0;
}
