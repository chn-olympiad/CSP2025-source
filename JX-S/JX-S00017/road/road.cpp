#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10001,M=1000001,Q=1500000;
int n,m,k,dist[N+11];
int a[11][N],c[11],vis[11],vis2[Q];
int tot,to[M*2],val[M*2],nxt[M*2],head[N];
void build(int u,int v,int w){
	to[++tot]=v;
	val[tot]=w;
	nxt[tot]=head[u];
	head[u]=tot;
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > q;
void dijkstra(){
	for(int i=1;i<=n+k;i++)dist[i]=2147483647;
	dist[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int x=q.top().second;
		q.pop();
		if(vis2[x])continue;
		vis2[x]=1;
		for(int i=head[x];i;i=nxt[i]){
			int y=to[i],z=val[i];
			if(dist[x]+z<dist[y]){
				dist[y]=dist[x]+z;
				q.push(make_pair(dist[y],y));
			}
		}
	}
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		build(u,v,w);
		build(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[k];
		for(int j=1;j<=n;j++){
			cin>>a[k][j];
			build(n+i,j,a[k][j]);
			build(j,n+i,a[k][j]);
		}
	}
	dijkstra();
	int maxn=0;
	for(int i=1;i<=n+k;i++){
		maxn=max(maxn,dist[i]);
	}
	cout<<maxn;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
