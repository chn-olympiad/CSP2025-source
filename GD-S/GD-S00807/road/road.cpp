#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,k;
    cin>>n>>m>>k;
    long long u[m+1],v[m+1],w[m+1];long long c[k+1],a[k+1][n+1];
    for(int i=1;i<=m;i++){
    	cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	return 0;
} 
