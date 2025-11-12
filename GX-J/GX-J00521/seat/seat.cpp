#include <iostream>
#include <stdio.h>
int a[15][15];
int a[15][15];
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y,n;
    cin>>x>>y;
    for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cin>>a[i][j];
		}
	}
	n=a[x][y];
	for(int k=0;k<x*y;k++){
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				if(a[i][j]<a[i][j+1]){
					b[0]=a[i][j];
					a[i][j]=a[j+1];
					a[i][j+1]=b[0];
				}
			}
		}
	}
	
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(a[i][j]==n){
				cout<<i+1<<" "<<j+1;
				break;
			}
		}
	}
    return 0;
}

