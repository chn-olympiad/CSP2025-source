#include<bits/stdc++.h>
using namespace std;
int seat[15][15];
int in[105],R; 
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,w;
	cin>>h>>w;
	for(int i=1;i<=h*w;i++) cin>>in[i];
	R=in[1];
	sort(in+1,in+1+h*w,cmp);
	int jsq=1;
	for(int i=1;i<=h;i++){
		if(i%2==1) for(int j=1;j<=w;j++){
			seat[i][j]=in[jsq];
			jsq++;
		}
		else for(int j=w;j>=1;j--){
			seat[i][j]=in[jsq];
			jsq++;
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(seat[i][j]==R){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
