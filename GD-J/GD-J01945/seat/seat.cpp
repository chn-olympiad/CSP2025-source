#include<bits/stdc++.h>
using namespace std;
int a[15][15],numi=0;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<a[i][j]<<' ';
		}
	}
}
