//张天熠CZ-S00152遵义航天中学
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,t;
	cin>>t;
	for(int z=1;z<=t;z++){
	while(n%2!=0){
		cin>>n;
	}
	int a[n][4];
	for(int u=1;u<=n;u++){
		for(int q=1;q<=3;q++){
		cin>>a[u][q];
	}
	}
	int x[4]={0},e;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(a[i][j]<a[i+1][j]){
				int r=a[i][j];
				a[i][j]=a[i+1][j];
				a[i+1][j]=r;
			}
			if(a[i][j]>a[i][j+1]){
				a[i][j+1]=0;
			}
		}
	}
	int b=n/2;
	for(int i=1;i<=b;i++){
		for(int j=1;j<=3;j++){
			x[j]+=a[i][j];
		}
	}
	e=x[1]+x[2]+x[3];
	cout<<e;
}
}
