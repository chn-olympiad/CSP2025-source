#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[11],a[11][10010],u,v,w;
struct Edge{
	long long u,v,w; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		mapp[u][v]=w;
		mapp[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	
}
