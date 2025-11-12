#include<bits/stdc++.h>
using namespace std;

int n,m,k,f=1000;
int v[10000],u[1000000];
long long w[10008],c[10008],a[1008][1008];
void dfs(int x,int z){
	if(f>x)
		f=x;
	if(f<x)
		return;
	for(int i=1;i<=n;i++){
		int dx=c[i]+a[i][z]+w[i]+w[z];
		if(dx>x);
		dfs(dx,z-1);
	}
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	dfs(0,k);
	cout<<f;
	return 0;
}
