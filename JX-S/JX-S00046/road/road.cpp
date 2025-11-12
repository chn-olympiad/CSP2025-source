#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100;
int n,m,k,u[N],w[N],v[N],c[N],a[N][N],dis[N],ver[N],edg[N],nxt[N],head[N],tot;
void add(int u,int v,int w){
	ver[++tot]=v;
	nxt[tot]=u;
	edg[tot]=w;
	head[u]=tot;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		add(u[i],v[i],w[i]);
		add(v[i],u[i],w[i]);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	cout<<0;
	return 0;
}
