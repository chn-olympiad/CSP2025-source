#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n,a1;
	cin>>m>>n;
	int d[101][101],a[110];
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	a1=a[1];
	int max=0,c;
	for(int i=1;i<=m*n;i++){
	for(int i=1;i<=m*n;i++){
		if(a[i-1]<a[i]){
			c=a[i-1];
			a[i-1]=a[i];
			a[i]=c;
			c=0;
		}
	}
}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(m%2!=0){
				d[i][j]=a[i*j];
			}
			if(m%2==0){
				d[i][j]=a[m*n-i*j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(d[i][j]==a1){
				cout<<i<<' '<<j;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
