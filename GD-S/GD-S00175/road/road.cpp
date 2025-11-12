//B
#include<bits/stdc++.h>
using namespace std;
struct edge{
	int v,w;
};
struct node{
	int u;
	long long cost;
	bool operator < (const node x)const{
		return x.cost<cost;
	}
};
const int N=10020;
int vis[N];
vector<edge> g[N];
priority_queue<node> q;
int n,m,k;
int extra_cost[15];
long long c[N];
long long ans=-1;
int main(){
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
		cin>>extra_cost[i];
		for(int j=1;j<=n;j++){
			int a;cin>>a;
			g[j].push_back({i+n,a});
			g[i+n].push_back({j,a});
		}
	}
	q.push({1,0});
	for(int i=1;i<=n+k;i++)c[i]=1e18;
	c[1]=0;
	while(!q.empty()){
		int u=q.top().u;
		long long cost=q.top().cost;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto x:g[u]){
			int v=x.v;
			int w=x.w;
			long long total=cost+w;
			if(total<c[v]){
				c[v]=total;
				q.push({v,total});
			}
		}
	}
	for(int i=1;i<=n;i++)ans=max(ans,c[i]);
	cout<<ans;
	return 0;
}
