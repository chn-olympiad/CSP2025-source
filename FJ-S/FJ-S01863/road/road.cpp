#include<bits/stdc++.h>
using namespace std;

int a[10000000][100000000];
int main(){
	preopen("road.in","r","stdin");
	preopen("road.out","r","stdout");
    int n,m,k,i,j,o;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cin>>a[i][j];
		}
	}
	for(int o=1;o<=k;o++){
		for(int l=1;l<=n+1;l++){
			if(n>=10^3&&m>=10^5&&k<=10&&k>=5){
				a[1][l]=0;
			}
			cin>>a[o][l];
		}
	}
	return 0;
}
