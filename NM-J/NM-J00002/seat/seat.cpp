#include <iostream>
#include <string>
using namespace std;
int main (){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	long long n=0;
	long long m=0;
	scanf("%lld",&n);
	scanf("%lld",&m);
	long long x[105][105]={};
	long long r[105][105]={};
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>x[i][j];
			r[1][1]=x[1][1];
			
		}
		
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(x[i][j]>x[i][j-1]&&x[i][j-1]!=0){
				r[2][2]=x[i][j];
				x[i][j]=x[i][j-1];
				x[i][j-1]=r[2][2];
				}
			if(x[i][j]>x[i-1][j]&&x[i-1][j]!=0){
				r[3][3]=x[i][j];
				x[i][j]=x[i-1][j];
				x[i-1][j]=r[3][3];
				}
			if(x[i][j]>x[i][j+1]&&x[i][j+1]!=0){
				r[8][8]=x[i][j];
				x[i][j]=x[i][j+1];
				x[i][j+1]=r[8][8];
				}
			if(x[i][j]>x[i+1][j-1]&&x[i+1][j-1]!=0){
				r[9][9]=x[i][j];
				x[i][j]=x[i+1][j-1];
				x[i+1][j-1]=r[9][9];
				}
			
			/*if(x[i][j]>x[i+1][j+1]&&x[i+1][j+1]!=0){
				r[5][5]=x[i][j];
				x[i][j]=x[i+1][j+1];
				x[i+1][j+1]=r[5][5];
				}*/
			/*if(x[i][j]>x[i-1][j+1]&&x[i-1][j+1]!=0){
				r[6][6]=x[i][j];
				x[i][j]=x[i-1][j+1];
				x[i-1][j+1]=r[6][6];
				}*/
			/*if(x[i][j]>x[i+1][j-1]&&x[i+1][j-1]!=0){
				r[7][7]=x[i][j];
				x[i][j]=x[i+1][j-1];
				x[i+1][j-1]=r[7][7];
				}*/
			/*if(x[i][j]>x[i-1][j-1]&&x[i-1][j-1]!=0){
				r[4][4]=x[i][j];
				x[i][j]=x[i-1][j-1];
				x[i-1][j-1]=r[4][4];
				}*/
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(x[i][j]==r[1][1]){
				cout<<j<<" "<<i;
				}
		}
	}
	return 0;
}
