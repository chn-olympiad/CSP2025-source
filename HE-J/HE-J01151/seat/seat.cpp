#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	int seat[x][y];
	int inp[x*y];
	for(int i=0;i<x*y;i++){
		cin>>inp[i];
	}
	int xm=inp[0];
	int px[x*y]={0};
	int max=inp[0];
	for(int i=0;i<x*y;i++){
		for(int j=0;j<x*y;j++){
			if(inp[j]>inp[max]) max=j;
		}
		px[i]=inp[max];
		inp[max]=-1;
	}
	for(int i=0;i<x;i++){
		int pxj=i*x;
		if(i%2==0){
			for(int j=0;j<y;j++){
				seat[i][j]=px[pxj];
				pxj++;
			}
		}
		else{
			for(int j=y-1;j>-1;j--){
				seat[i][j]=px[pxj];
				pxj++;
			}
		}
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(seat[i][j]==xm){
				cout<<i+1<<" "<<j+1;
			}
		}
	}
	return 0;
}
