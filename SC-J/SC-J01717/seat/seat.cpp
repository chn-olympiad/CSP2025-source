#include<bits/stdc++.h>
using namespace std;
int a,b,c[20][20],d;
void swa(int ax,int bx,int cx,int dx){
	int as=c[ax][bx];
	c[ax][bx]=c[cx][dx];
	c[cx][dx]=as;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<b;i++){
		if(i%2==1){
			for(int j=a-1;j>=0;j--){
				cin>>c[j][i];
			}
		} 
		else{
			for(int j=0;j<a;j++){
				cin>>c[j][i];
				if(i==0&&j==0)d=c[j][i];
			}
		}
	}
	for(int j=0;j<b;j++){
		for(int i=0;i<a;i++){
			if(j%2==1){
				if(i!=0&&c[i][j]<c[i-1][j])swa(i,j,i-1,j);
				else if(c[i][j]<c[i][j+1])swa(i,j,i,j+1);
			}else{
				if(i!=a-1&&c[i+1][j]>c[i][j])swa(i+1,j,i,j);
				else if(c[i][j+1]>c[i][j])swa(i,j+1,i,j);
			}
		}
	}
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			if(d==c[i][j]){
				cout<<j+1<<" "<<i+1;
			}
		}
	}
	return 0;
}