#include<windows.h> //windows lib
#include <GL/glut.h> //opengl lib
#include <stdio.h> //standard function lib
#include<string> //string lib
#define collisioncheck 1 //to turn collision detection->1 , and off-


//let's create menu items

int texchangeid,terchangeid,speedchangeid,sunshowid,sunsizeid,sunspinid,settimeid,daylenid;

//flags declaration


int COLLISIONCHECKTIME=1;				//check for collision ever millisecond
int JUMPSPEED=8;					//speed of jump: 125 pixel/sec, jump time: 2.4sec
int MAX_HEIGHT=150;					//max height that can be reached by T_Rex: 150
int DASH_CACT_SAND=3;					//speed of cactus: 333.33 pixels/sec, Time to attack: 6 sec
int SCREEN_CENTERX=1000;				//center X coordinate for the screen: 1000
int SCREEN_CENTERY=250;					//center Y coordinate for the screen: 250
int numOfBlock=25;					//number of cactus position stored: 25
int numOfGrass=200;				//number of sand granule in the desert Land
int numOfMegh=4;					//number of megh
int numOfTree=30; //number of tree
int numOfRoad=20;
int ANGULAR_SPEED=5;					//angular speed: 142.86 degree/sec, time to complete a full rotation: 2.52 sec
int ZOOMING=1;						//rate at which rectangle expands: 166.67 pixles/sec



//Tom drawing
//TOM BODY
GLdouble tomBodyx[]={
   498.4, 409, 344.1, 368.7, 458.1, 523
};
GLdouble tomBodyy[]={
    773.9, 797.1, 731.3, 642.3, 619, 684.8
};
//TOM EARS
GLdouble tomEarx[]={
428, 391, 361.3, 368.6, 405.6, 435.3
};
GLdouble tomEary[]={
679.8, 692.7, 667.2, 628.7, 615.8, 641.3
};
//TOM OUTEREYE
GLdouble tomOuteyex[]={
503.3, 475.3, 452.8, 458.3, 486.3, 508.8
};
GLdouble tomOuteyey[]={
693.2, 703, 683.6, 654.5, 644.7, 664
};
//TOM EYEBALL
GLdouble tomEyeballx[]={
 503.8, 491.3, 481.3, 483.8, 496.3, 506.3
};
GLdouble tomEyebally[]={
690.5, 694.9, 686.2, 673.2, 668.8, 677.5
};
//TOM MOUTH
GLdouble tomMouthx[]={
506.3, 440, 447.5, 512.9
};
GLdouble tomMouthy[]={
748.6, 734.7, 716.4, 732.5
};
//TOM NOSE
GLdouble tomNosex[]={
516.3, 503.8, 493.8, 496.3, 508.8, 518.8
};
GLdouble tomNosey[]={
729.7, 734.1, 725.5, 712.4, 708.1, 716.7
};



//Jerry drawing
//jerry body
GLfloat jerryBodyx[]={
    891.8, 828.5, 796.9, 828.5, 891.8, 923.5
};
GLfloat jerryBodyy[]={
680.3, 680.3, 735.1, 789.9, 789.9, 735.1
};
//jerry ears
GLdouble jerryEarsx[]={
840.5, 816.8, 805, 816.8, 840.5, 852.3
};
GLdouble jerryEarsy[]={
674, 674, 694.5, 715, 715, 694.5
};
//jerry outereye
GLdouble jerryOuterEyex[]={
891.8, 872, 862.1, 872, 891.8, 901.7
};
GLdouble jerryOuterEyey[]={
689.3, 689.3, 706.5, 723.6, 723.6, 706.5
};
//jerry eyeball
GLdouble jerryEyeballx[]={
892.6, 884.2, 879.9, 884.2, 892.6, 896.9
};
GLdouble jerryEyebally[]={
699.1, 699.1, 706.5, 713.8, 713.8, 706.5
};
//jerry mouth
GLdouble jerryMouthx[]={
915.3, 894.1, 883.5, 894.1, 915.3, 926
};
GLdouble jerryMouthy[]={
730.8, 730.8, 749.2, 767.6, 767.6, 749.2
};
//jerry nose
GLdouble jerryNosex[]={
920.2, 910.8, 906.2, 910.8, 920.2, 924.9
};
GLdouble jerryNosey[]={
720.8, 720.8, 728.9, 737, 737, 728.9
};

//fields Coordinates
GLfloat fieldx[]={
0.0,1920.0,1920.0,0.0
};
GLfloat fieldy[]={
0.0,0.0,490.0,490.0
};
//field color



//tree coordinates
//Upper side of tree
GLdouble treeUpx[]={
1243.9, 1182, 1141.7, 1163.1, 1225, 1265.3
};
GLdouble treeUpy[]={
531.7, 542.6, 494.5, 435.5, 424.6, 472.7
};
//tree wood
GLdouble treeWoodx[]={
1196.5, 1190, 1216, 1212.1
};
GLdouble treeWoody[]={
530.1, 599.6, 599.6, 529.5
};

//grass coordinates
GLdouble grassx[]={
122, 133, 122, 157, 157
};
GLdouble grassy[]={
1080, 1042, 982, 1042, 1080
};

//Megh coordinates
GLdouble meghx[]={
419.7, 326.8, 233.9, 233.9, 326.8, 419.7
};
GLdouble meghy[]={
146.7, 174.2, 146.7, 91.6, 64.1, 91.6
};

//road thin
GLdouble roadx[]={
9.8, 87.8, 86.8, 9.8
};
GLdouble roady[]={
792.4, 791.7, 804.7, 805.3
};

//blocks
GLdouble blockx[]={
1066.6, 1100.9, 1111.3, 1056.5
};
GLdouble blocky[]={
728.6, 748.8, 789.9, 789.9
};



///////starting position of everything

//vertices for the kill screen sqaure
GLfloat killscrnxmsg[]={-3,3,3,-3};
GLfloat killscrnymsg[]={-3,-3,3,3};



//Starting vertices of killscrnsquare
GLfloat killscrnx[]={-3,3,3,-3};
GLfloat killscrny[]={-3,-3,3,3};



//Dynamic vertices of killscrnsquare
GLfloat killscrnangle=0;
GLint killscrnover=0;

GLfloat cactposmsg[]=
{1920, 2000.0,2830.0,3600.0,4450.0,5320.0,6210.0,6980.0,7790.0,8630.0,9500.0,10300.0,11180.0,12070.0,12880.0,13750.0,14580.0,15430.0,16200.0,



16990.0,17880.0,18680.0,19550.0,20450.0,21200.0,22000.0};



//Starting position of cactus



GLfloat cactpos[]=
{1920, 2000.0,2830.0,3600.0,4450.0,5320.0,6210.0,6980.0,7790.0,8630.0,9500.0,10300.0,11180.0,12070.0,12880.0,13750.0,14580.0,15430.0,16200.0,



16990.0,17880.0,18680.0,19550.0,20450.0,21200.0,22000.0};


GLfloat height=0.0;					//height in the air
GLint jflag=0;						//Jump Flag;
GLint jcount=0;						//jump Count;
int gameover=0;						//flag for game is over or not
int score=0;						//variable to count score

//Text to diaplay on cover screen
char textb[]={"Graphic Design"};
char textc[]={"Project Name: tom&jerry"};
char textd[]={"theme       : tom is running to catch jerry"};
char texte[]={"<<-------------- INSTRUCTIONS --------------->>"};
char textf[]={"Press 'w' or 'W' or <Spacebar Key> to make T-Rex Jump"};
char textg[]={"Press 'r' or 'R' to Restart the game"};
char texth[]={"Press 's' or 'S' to start the game"};
char texti[]={"Press the right mouse button to access Menu"};
char textj[]={"Press <ESC Key> to quit the game"};


GLint gameStart=0;					//Game has started or not
GLuint displayID1,displayID2,displayID3,displayID4,displayID5,displayID6,displayID7,displayID8;				//declaration for displaylist



void drawText(GLint x,GLint y,char* str)		//to draw a string of character(One character at a time) at position x,y
{   int i;
    glRasterPos2f(x,y);
    for(i=0;i<strlen(str);i++)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
}

/////////Drawing Cat()
void drawTom(){
int i;
glBegin(GL_POLYGON);
glColor3f(0.4941,0.52941,0.52941);
for(i=0;i<129;i++){
    glVertex2f(tomBodyx[i],tomBodyy[i]); //body
}
glEnd();


        glBegin(GL_POLYGON);
        glColor3f(0.976, 0.705, 0.619);
        for(i=0;i<59;i++){
            glVertex2f(tomEarx[i],tomEary[i]); //ears
}
glEnd();
                    glBegin(GL_POLYGON);
                    glColor3f(0.976, 0.9254, 0.46666);
                    for(i=0;i<45;i++){
                        glVertex2f(tomOuteyex[i],tomOuteyey[i]); //OuterEye
}
glEnd();
                                glBegin(GL_POLYGON);
                                glColor3f(0.07843, 0.11764, 0.070588);
                                for(i=0;i<20;i++){
                                    glVertex2f(tomEyeballx[i],tomEyebally[i]); //eyeBall
}
glEnd();
                                            glBegin(GL_POLYGON);
                                            glColor3f(1, 1, 1);
                                            for(i=0;i<55;i++){
                                                glVertex2f(tomMouthx[i],tomMouthy[i]); //mouth
}
glEnd();
                                                        glBegin(GL_POLYGON);
                                                        glColor3f(0.07843, 0.11764, 0.070588);
                                                        for(i=0;i<20;i++){
                                                            glVertex2f(tomNosex[i],tomNosey[i]); //nose
}
glEnd();


} //end of tomDrawing


/////////Drawing Jerry()
void drawJerry(){
int i;
glBegin(GL_POLYGON);
glColor3f(0.7764, 0.513, 0.16470);
for(i=0;i<5;i++){

    glVertex2f(jerryBodyx[i],jerryBodyy[i]); //body

}
glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.9647, 0.6352, 0.709);
        for(i=5;i<11;i++){
            glVertex2f(jerryEarsx[i],jerryEarsy[i]); //ears
}
glEnd();
                    glBegin(GL_POLYGON);
                    glColor3f(1,1,1);
                    for(i=11;i<17;i++){
                        glVertex2f(jerryOuterEyex[i],jerryOuterEyey[i]); //OuterEye
}
glEnd();
                                glBegin(GL_POLYGON);
                                glColor3f(0.0235, 0.027450, 0.027450);
                                for(i=17;i<23;i++){
                                    glVertex2f(jerryEyeballx[i],jerryEyebally[i]); //eyeBall
}
glEnd();
                                            glBegin(GL_POLYGON);
                                            glColor3f(1, 0.901, 0.77254);
                                            for(i=23;i<29;i++){
                                                glVertex2f(jerryMouthx[i],jerryMouthy[i]); //mouth
}
glEnd();
                                                        glBegin(GL_POLYGON);
                                                        glColor3f(0.0235, 0.027450, 0.027450);
                                                        for(i=29;i<34;i++){
                                                            glVertex2f(jerryNosex[i],jerryNosey[i]); //nose
}
glEnd();


} //end of jerryDrawing

void drawField(){
int i;
glBegin(GL_POLYGON);
glColor3f(0.4549, 0.7215, 0.48235);
for(i=0;i<4;i++){
    glVertex2f(fieldx[i],fieldy[i]);
}
glEnd();
}

void drawGrass(){
int i;
glBegin(GL_POLYGON);
glColor3f(0.2274, 0.69411, 0.2901);
for(i=0;i<numOfGrass;i++){
    glVertex2f(grassx[i],grassy[i]);
}
glEnd();
}
void drawMegh(){
int i;
glBegin(GL_POLYGON);
glColor3f(0.75686, 0.901, 0.9254901);
for(i=0;i<numOfMegh;i++){
    glVertex2f(meghx[i],meghy[i]);
}
glEnd();
}
void drawBlock(){
int i;
glBegin(GL_POLYGON);
glColor3f(0.6627, 0.117647, 0.13333);
for(i=0;i<numOfBlock;i++){
    glVertex2f(blockx[i],blocky[i]);
}
glEnd();
}

void drawTree(){
int i;

for(i=0;i<numOfTree;i++){
    glBegin(GL_POLYGON);
    glColor3f(0.6156, 0.454, 0.16862);
    for(int j=0;j<numOfTree;j++){
    glVertex2f(treeUpx[i],treeUpy[i]);
    glEnd();
    }
                glBegin(GL_POLYGON);
                glColor3f(0.152941, 0.5411, 0.26274);
                for(int k=0;k<numOfTree;k++){
                glVertex2f(treeWoodx[i],treeWoody[i]);
                glEnd();
                }

}
}//end of tree

void drawRoad(){
int i;
glBegin(GL_POLYGON);
glColor3f(0.2901, 0.6, 0.2862);
for(i=0;i<numOfRoad;i++){
    glVertex2f(roadx[i],roady[i]);
}
glEnd();
}
void drawkillscrnsquare()				//draw kill screen square
{
int i;
glBegin(GL_POLYGON);
glColor3f(0.109375,0.222656,0.730468);		//Persian Blue
for(i=0;i<4;i++)
glVertex2f(killscrnx[i],killscrny[i]);
glEnd();
}

void drawCoverPage()					//drawing the cover page
{
glClearColor(0.0,0.52,0.79,1.0);
glColor3f(1.0,1.0,1.0);
drawText(0642.857143,400.0,textb);	//draw textb
drawText(0842.857143,350.0,textc);	//draw textc
drawText(0857.142857,300.0,textd);	//draw textd
drawText(0385.714286,250.0,texte);	//draw texte
drawText(0585.714286,225.0,textf);	//draw textf
drawText(0748.571429,200.0,textg);	//draw textg
drawText(0771.428571,175.0,texth);	//draw texth
drawText(0677.142857,150.0,texti);	//draw texti
drawText(0748.571429,125.0,textj);	//draw textj
}

void drawScnFreez()					//displaying the scoreand GAME OVER
{
char result[10];
sprintf(result,"SCORE: %d",score);		//store score in result
glClearColor(0.109375,0.222656,0.730468,1.0);	//Persian blue
glColor3f(1.0,0.0,0.0);				//red
drawText(800,350,"GA    ME OVER");			//display GAME OVER message
drawText(700,250,"T_Rex is hurt ");		//display trex is hurt
drawText(750,150,result);			//display the result
}

void plotTree(GLfloat pos)				//plotting cactus in right positionwithrespect to left side of the screen
{
glPushMatrix();
glTranslatef((pos-320.0),540,0.0);		//now the distance of the posis from the right
glCallList(displayID1);				//now draw the cactus with respect to left side of the screen
glPopMatrix();
}

void plotGrass(GLfloat pos)				//plotting cactus in right positionwithrespect to left side of the screen
{
glPushMatrix();
glTranslatef((pos-320.0),0,0.0);		//now the distance of the posis from the right
glCallList(displayID2);				//now draw the cactus with respect to left side of the screen
glPopMatrix();
}

void plotMegh(GLfloat pos)				//plotting cactus in right positionwithrespect to left side of the screen
{
glPushMatrix();
glTranslatef((pos-320.0),700,0.0);		//now the distance of the posis from the right
glCallList(displayID1);				//now draw the cactus with respect to left side of the screen
glPopMatrix();
}
void plotRoad(GLfloat pos)				//plotting cactus in right positionwithrespect to left side of the screen
{
glPushMatrix();
glTranslatef((pos-320.0),200,0.0);		//now the distance of the posis from the right
glCallList(displayID3);				//now draw the cactus with respect to left side of the screen
glPopMatrix();
}
void plotBlock(GLfloat pos)				//plotting cactus in right positionwithrespect to left side of the screen
{
glPushMatrix();
glTranslatef((pos-320.0),201,0.0);		//now the distance of the posis from the right
glCallList(displayID4);				//now draw the cactus with respect to left side of the screen
glPopMatrix();
}


//Jumping of jerry
void flying()
{
if(jflag==1 && height<MAX_HEIGHT)		//if jumping and below max height
height++;				//increase height
else if(jflag==1 && height==MAX_HEIGHT)		//if reached max height
jflag=-1;				//start falling
}
//falling of jerry
void falling()
{
if(jflag==-1 && height>0)			//if falling and didn't reach groumd
height--;				//decrease height
else if(jflag==-1 && height==0)			//if reached ground
{
jflag=0;				//be in a state to be ready to jump
jcount--;				//release the jump lock
}
}



void animateJerry(int value)				//animation for Jerry's jumping;
{
if(gameStart!=0)
{
flying();				//upward movement of T_Rex
falling();				//downward movement of T_Rex
glutPostRedisplay(); 			//Inform GLUT that the display has changed;
}
glutTimerFunc(JUMPSPEED,animateJerry,0);		//Call animateTRex after each 8 millisecond;
}



void animateBlock(int value)				//animation,reset and check collision for cactus;
{
int i;
if(gameStart!=0)
{
for(i=0;i<numOfBlock;i++)			//for ever cactus object
{
if(cactpos[i]==-40)		//to reset the position of cactus once the pass T_Rex



			       cactpos[i]=(cactposmsg[i]+cactposmsg[numOfBlock-1]);//reset



			cactpos[i]--;			//left movement of cactus
		//left movement of cactus
}
glutPostRedisplay(); 			// Inform GLUT that the display has changed;
}
glutTimerFunc(DASH_CACT_SAND,animateBlock,0);	//Call animateCactus after each 3 millisecond;
}

void animateField(int value)				//animation,reset and check collision for cactus;
{
int i;
if(gameStart!=0)
{
for(i=0;i<numOfRoad;i++)		//for ever cactus object
{
if(fieldx[i]==0)			//if sand granule reaches the end
fieldx[i]=1920;		//reset its position
fieldx[i]--;			//till then move the sand
}
glutPostRedisplay(); 			// Inform GLUT that the display has changed;
}
glutTimerFunc(DASH_CACT_SAND,animateField,0);	//Call animateCactus after each 3 millisecond;
}


void killSrcnSquareRotation(int value)			//angle updater for kill screen square



{



	killscrnangle++;				//increase angle



	if(killscrnangle>360.0)				//if angle is more than 360 degree



		killscrnangle-=360.0;			//recalculate the angle



	glutPostRedisplay(); 				// Inform GLUT that the display has changed;



	glutTimerFunc(ANGULAR_SPEED,killSrcnSquareRotation,0);//call killSrcnSquareRotation after each 14 milliseconds



}



void killSrcnSquareScaling(int value)			//scaling the kill screen square



{







	if(gameover && !killscrnover)			//if game is over and kill screen is not covered



	{						//scale the coordinated of the kill screen square



		killscrnx[0]-=0.5;			//		A



		killscrnx[1]+=0.5;			//		|



		killscrnx[2]+=0.5;			//		|



		killscrnx[3]-=0.5;			//		|



		killscrny[0]-=0.5;			//		|



		killscrny[1]-=0.5;			//		|



		killscrny[2]+=0.5;			//		|



		killscrny[3]+=0.5;			//		|



   	}						//		V



   	if(killscrnx[0]==-1050)				//if kill screen is fully covered



   		killscrnover=1;				//tell that kill screen is fully covered



	glutPostRedisplay(); 				// Inform GLUT that the display has changed;



	glutTimerFunc(ZOOMING,killSrcnSquareScaling,0);	//call killSrcnSquareScaling after each 14 milliseconds



}



void endScreen()					//animation in the end screen

{



	glPushMatrix();



	glTranslatef(SCREEN_CENTERX,SCREEN_CENTERY,0.0);//transfer the kill screen square to the middle of the screen



	glRotatef(killscrnangle,0.0,0.0,1.0);		//rotate the kill screen square



	drawkillscrnsquare();				//draw the kill screen square



   	glPopMatrix();



}

void checkCollision(int value)				//check if game is over or not and update scoreboard



{



	int i;



	if(collisioncheck)



	{



		for(i=0;i<numOfBlock;i++)			//for ever cactus object



		{



			if(cactpos[i]>=110 && cactpos[i]<=120)//if cactus is in range,be careful and so check if you hit a cactus and hurt T_Rex



				if(height<85 && !gameover)//if the jump is low, T_Rex is hurt; check if the cactus is touching the body or 	not



				{			//because in this case the body will be directly above the cactus



				     printf("Tom caught jerry\n");//T_Rex got hit



				     printf("Score:%d\n",score);//display score



				     gameover=1;	//Game Over



				}



			if(cactpos[i]>-10 && cactpos[i]<110)//if cactus is in range,be careful and so check if you hit a cactus and hurt T_Rex



				if(height<100 && !gameover)//if the jump is low, T_Rex is hurt



				{



				     printf("Tom caught jerry\n"); //T_Rex got hit



				     printf("Score:%d\n",score);//display score



				     gameover=1;	//Game Over



				}



			if(cactpos[i]>=-30 && cactpos[i]<=-10)//if cactus is in range,be careful and so check if you hit a cactus and hurt T_Rex



				if(height<85 && !gameover)//if the jump is low, T_Rex is hurt; check if the cactus is touching the body or 	not



				{			//because in this case the body will be directly above the cactus



				     printf("Tom caught jerry\n"); //T_Rex got hit



				     printf("Score:%d\n",score);//display score



				     gameover=1;	//Game Over



				}



			if(cactpos[i]==-40)		//to reset the position of cactus once the pass T_Rex



			       if(!gameover)		//if game is not over



			       		score+=100;	//add 100 points to be able to jump above the cactus



		}



	}



	glutPostRedisplay(); 				// Inform GLUT that the display has changed;



	glutTimerFunc(COLLISIONCHECKTIME,checkCollision,0);//Call animateCactus after each 33 millisecond;



}

void display()



{



	int i;



	char temp;



	glClear(GL_COLOR_BUFFER_BIT);			//Clear Color buffer bit



	if(gameStart==1)				//if the game has started



	{



		if(!gameover)				//if game is not over, play the game



		{



			glClearColor(0.1,0.1,0.1,1);					//dynamic background Color change



			if(jflag!=0)			//if T_Rex is not on ground



			{



				glPushMatrix();



 				glTranslatef(0.0,height,0.0);//Translate T_Rex to his height



 				drawJerry();		//draw T_Rex



   				glPopMatrix();



			}



			else if(jflag==0)		//if T_Rex is ready to jump



				drawJerry();		//draw T_rex on the Ground



				drawField();		//draw Desert sand





			for(i=0;i<numOfBlock;i++)		//for every cactus plant



				plotBlock(cactpos[i]);	//plot the cactus in their position



		}



		else					//if game is over



		{



			glClearColor(0.0,0.0,0.0,1.0);	//black



			if(!killscrnover)		//if the kill screen is not covered



				endScreen();		//if the game is over, show the GAME OVER screen



		}



		if(killscrnover)			//if screen is completely covered



			drawScnFreez();			//display the GAME OVER message







	}



    	else if(gameStart==0)				//cover Page of the Game



    	{



        	drawCoverPage();



        	glutPostRedisplay();			//changle has been made to the display so re display it



       	}



	glFlush();					//flush the output to the screen



	glutPostRedisplay();				//show any change if any



}











void reset()						//initilize or reset the value of constants to start a new game



{



	int i;




















	killscrnangle=0;				//		|



	killscrnover=0;					//		|



	height=0.0;					//		|



	jflag=0;					//		|



	jcount=0;					//		|



	gameover=0;					//		|



	DASH_CACT_SAND=3;				//		|



















	score=0;					//		|











	for(i=0;i<numOfBlock;i++)				//reset the position of cactus



		cactpos[i]=cactposmsg[i];



	for(i=0;i<4;i++)				//reset the value of the kill screen square



	{



		killscrnx[i]=killscrnxmsg[i];



		killscrny[i]=killscrnymsg[i];



	}




}











void keyboardEvent(unsigned char key,int x,int y)



{



	if(key==' '||key=='w'||key=='W') 		//if w or W or " " is pressed make T_rex jump once



		if(jcount==0)				//apply jumplock



		{



			jflag=1;			//jumping



			jcount++;			//number of jumps active,either 0 or 1



		}



	if(key==27)					//if c or C is pressed



		exit(0);				//Close



	if(key=='r'||key=='R')				//if r or R is pressed



		reset();				//Restart



	if(key=='s'||key=='S')				//if s or S is pressed



		gameStart=1;				//Start the Game



	display();					//call the display



}











void menu(int key1 )					//menu menu



{



	switch(key1)



	{



		case 1:	reset();



			gameStart=(gameStart+1)%2;



			break;



		case 2: exit(0);



		  	break;



	}



}



void speedchange(int key4)				//submenu to change the travelling speed



{



	switch(key4)



	{



		case 1:	DASH_CACT_SAND=3;



			break;



		case 2:	DASH_CACT_SAND=6;



			break;



		case 3:	DASH_CACT_SAND=9;



			break;



	}



}







void menusystem()					//main menu description function



{










	speedchangeid = glutCreateMenu(speedchange);



	glutAddMenuEntry("Normal",1);



	glutAddMenuEntry("Slow",2);



	glutAddMenuEntry("Slowest",3);









	glutCreateMenu(menu);



	glutAddMenuEntry("Re/Start Game",1);



	glutAddSubMenu("T-rex color",texchangeid);



	glutAddSubMenu("Terrain",terchangeid);



	glutAddSubMenu("Travelling speed",speedchangeid);



	glutAddSubMenu("Toggle Show Sun",sunshowid);



	glutAddSubMenu("Change sun size",sunsizeid);



	glutAddSubMenu("Toggle sun spin",sunspinid);



	glutAddSubMenu("Day-Night Cycle lenght",daylenid);



	glutAddSubMenu("Set time",settimeid);



	glutAddMenuEntry("Quit",2);



	glutAttachMenu(GLUT_RIGHT_BUTTON);







}




void myinit()						//initilization function



{



	glMatrixMode(GL_PROJECTION);



	glLoadIdentity();



	gluOrtho2D(0.0,1920.0,0.0,499.0);



	glMatrixMode(GL_MODELVIEW);



	displayID1 = glGenLists(1);			//Display List for drawing Cactus



	glNewList(displayID1,GL_COMPILE);



		drawBlock();



	glEndList();



	displayID2 = glGenLists(1);			//Display List for drawing sun



	glNewList(displayID2,GL_COMPILE);



		drawTree();



	glEndList();



}











int main(int argc,char** argv)				//MAIN FUNCION



{



	reset();					//start or restart the game



	glutInit(&argc,argv);



	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);



	glutInitWindowSize(1920,1080);			//window size



	glutInitWindowPosition(0,0);			//window position



	glutCreateWindow("Run T-REX Run");		//window tital name



	glutDisplayFunc(display);



	glutKeyboardFunc(keyboardEvent);



	myinit();					//initilization function



	menusystem();					//menu system



	glutTimerFunc(JUMPSPEED,animateJerry,0);		//timer to animate jumping of TRex



	glutTimerFunc(DASH_CACT_SAND,animateJerry,0);	//timer to animate movement of cactus



	glutTimerFunc(DASH_CACT_SAND,animateField,0);	//timer to animate movement of sand Granules



	glutTimerFunc(COLLISIONCHECKTIME,checkCollision,0);//timer to check collision between TRex and Cactus



	glutTimerFunc(ANGULAR_SPEED,killSrcnSquareRotation,0);//timer to animate rotation of kill screen square



	glutTimerFunc(ZOOMING,killSrcnSquareScaling,0);	//timer to animate scaling of the kill screen square











	glutMainLoop();



	return 0;



}
