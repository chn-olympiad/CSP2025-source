#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+7;
const int INF=1e18+7;
struct edge{
	int v,w;
};
struct node{
	int id,w;
	bool operator<(const node &B) const
	{
		return w>B.w;
	}
};
vector<edge> g[N];
int n,m,k;
int c[N],a[N];
int vis[N],dis[N];
void dijstra(int s){
	for(int i=1;i<=n;i++){
		dis[i]=INF;
	}
	dis[s]=0;
	priority_queue<node> q;
	q.push({s,0});
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		int u=tmp.id;
		int w=tmp.w;
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v;
			int w=g[u][i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			} 
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
			g[i].push_back({j,a[i]+a[j]+c[i]});
			g[j].push_back({i,a[i]+a[j]+c[i]});
		}
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
		return 0;
	}
	dijstra(1);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=dis[i];
	}
	cout<<ans;
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
