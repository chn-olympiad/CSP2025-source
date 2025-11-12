#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int N=10,M=30;
char mapp[N+1][M+1];
//some doggy ASCII artwork
/*
char a[2][6]={"//^-,",
			  "| \\ "};
			  
char b[2][6]={"//^^ ",
			  "/| '\ "};
			  
char c[2][6]={"(_/^^",
			  "/ /'|"};
			  
char d[2][6]={"(_/^^,",
			  " )_|| "};
			  
char e[2][6]={" Zzz ",
			  "/-<^^"};
			  
char f[2][6]={"(_-^^ ",
			  "| {U}\ "};
			  		*/
struct being{
	int health,dir,mood,x=N,y=20;
}dog;
void wait(int mill){
	Sleep(mill);
}
/*
void printd(int q){
	if(dog.x<1)dog.x=1;
	if(dog.y<2)dog.y=2;
	if(dog.x>N)dog.x=N;
	if(dog.y>M-1)dog.y=M-1;
	int x=dog.x,y=dog.y;
	if(q==1){
		mapp[x][y]=a[1][2];
		mapp[x-1][y-2]=a[0][0];
		mapp[x-1][y-1]=a[0][1];
		mapp[x-1][y]=a[0][2];
		mapp[x-1][y+1]=a[0][3];
		mapp[x-1][y+2]=a[0][4];
		mapp[x][y-2]=a[1][0];
		mapp[x][y-1]=a[1][1];
		mapp[x][y+1]=a[1][3];
		mapp[x][y+2]=a[1][4];
	}
	if(q==2){
		mapp[x][y]=b[1][2];
		mapp[x-1][y-2]=b[0][0];
		mapp[x-1][y-1]=b[0][1];
		mapp[x-1][y]=b[0][2];
		mapp[x-1][y+1]=b[0][3];
		mapp[x-1][y+2]=b[0][4];
		mapp[x][y-2]=b[1][0];
		mapp[x][y-1]=b[1][1];
		mapp[x][y+1]=b[1][3];
		mapp[x][y+2]=b[1][4];
	}
}
void print(){
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cout<<mapp[i][j];
		}
	}cout<<"\n";
} 
*/
int random(int r){
	return rand()%r+1;//1~r
}

int main(){	
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int qwer[1005];
    int n;
    cin>>n;
    
    for(int thisIsForWastingT=1;thisIsForWasting<=n;thisIsForWasting++){
    	cin>>qwer[thisIsForWasting];
	}
	wait(1000);
	srand(time(0));
	cout<<random(214700000);
	while(1){
		system("cls");
		
		Sleep(1000);
	} 
	return 0;
}
