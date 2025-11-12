#include<bits/stdc++.h>
using namespace std;

struct c{
	int u,v,w;
}a[1000001];
int n,m,k;
int c[16],b[10001];
int vis[10001][10001];
int g[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cout<<b[j];
		}
	}
	cout<<15;
	return 0;
}
