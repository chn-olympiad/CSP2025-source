#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int n,m;cin>>n>>m;
	int a[n*m+5]={};
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
    int num=1;
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1])num++;
	}
	int b[255][255]={};
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				if(j==1){
					b[i][j]=b[i-1][j]+1;
				}
				else b[i][j]=b[i][j-1]+1;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(j==n)b[i][j]=b[i-1][j]+1;
				else b[i][j]=b[i][j+1]+1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==num){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0; 
}
