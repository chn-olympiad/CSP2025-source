#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int n,m;
int p;
int main(){
cin>>n>>m;
int a[n+1][m+1];
int k=n*m;
int b[k+1];
for(int i=1;i<=k;i++){
	cin>>b[i];
}
p=b[1];
for(int i=1;i<=k-1;i++){
	for(int j=i+1;j<=k;j++){
		if(b[i]<b[j]){
			swap(b[i],b[j]);
		}
	}
}
int hg=1;
for(int i=1;i<=m;i++){
	for(int j=1;j<=n;j++){
		if(i%2==1){
			a[i][j]=b[hg];
			hg++;
		}
		else{
			a[i][n-j+1]=b[hg];
			hg++;
		}
	}
}
for(int i=1;i<=m;i++){
	for(int j=1;j<=n;j++){
		if(a[i][j]==p){
			cout<<i<<" "<<j;
			break;
		}
	}
}
	return 0;
}
