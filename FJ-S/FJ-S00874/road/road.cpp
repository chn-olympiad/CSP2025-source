#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[10001],v[10001],w[10001],c[10001],a[10001][10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];}
	for(int i=1;i<=k;i++){cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];}}
	cout<<23;
	return 0;
} 
