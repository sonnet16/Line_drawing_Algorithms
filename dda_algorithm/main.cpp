#include<windows.h>
#include<stdio.h>
#include <GL/gl.h>

#include <GL/glut.h>

float x1,y1,x2,y2,m,i,j;

int dx=0,dy=0;

void display(void)

{

/* clear all pixels */

glClear (GL_COLOR_BUFFER_BIT);

/* draw white polygon (rectangle) with corners at

*	(0.25, 0.25, 0.0) and (0.75, 0.75, 0.0) */

glColor3f (0.0, 1.0, 0.0);

glBegin(GL_POINTS);

    if(dx==1){

        for(i=x1,j=y1;i<=x2,j<=y2;i=i+1,j=j+m){

            glVertex3f ((i/100), (j/100), 0.0);
            printf("(%.0f,%.0f)\t",i,j);

        }

    }

    else if(dy==1){

        for(i=x1,j=y1;i<=x2,j<=y2;i=(i+(1/m)),j=j+1){

            glVertex3f ((i/100), (j/100), 0.0);
            printf("(%.0f,%.0f)\t",i,j);

        }

    }

    else if (dx==-1){
         for(i=x1,j=y1;i>=x2,j>=y2;i=i-1,j=j-m){

            glVertex3f ((i/100), (j/100), 0.0);
            printf("(%.0f,%.0f)\t",i,j);

        }
    }

     else if (dy==-1){
         for(i=x1,j=y1;i>=x2,j>=y2;i=(i-(1/m)),j=j-1){

            glVertex3f ((i/100), (j/100), 0.0);
            printf("(%.0f,%.0f)\t",i,j);

        }
    }




glEnd();

/* don't wait!

*	start processing buffered OpenGL routines */

glFlush ();

}

void init (void)

{

/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();

glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
/*

gluOrtho2D(-300, 300, 0, 600);

*/


}

/*

*	Declare initial window size, position, and display mode

*	(single buffer and RGBA). Open window with "hello"

*	in its title bar. Call initialization routines.

*	Register callback function to display graphics.

*	Enter main loop and process events.

*/

int main(int argc, char** argv)

{

    printf("Enter first point: ");

    scanf("%f %f",&x1,&y1);

    printf("Enter second point: ");

    scanf("%f %f",&x2,&y2);

    m=(y2-y1)/(x2-x1);

    if((x1<x2)&&(y1<y2) && (m<=1)){

        dx=1;

    }
    else if((x1<x2)&&(y1<y2) && (m>1)){

        dy=1;

    }
    else if((x1>x2)&&(y1>y2) && (m<=1)){

        dx=-1;

    }

    else if((x1>x2)&&(y1>y2) && (m>1)){

        dy=-1;

    }



    glutInit(&argc, argv);


    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize (500, 500);

    glutInitWindowPosition (100, 100);

    glutCreateWindow ("DDA algorithm implementation");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0; /* ISO C requires main to return int. */

}
