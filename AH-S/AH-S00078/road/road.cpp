#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p;
ll n,m,k,dis[10055],Mst,vis[10055],cnt;
vector<p> g[10055];
ll prim(){
	Mst=0;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<p,vector<p>,greater<p>> q;
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()){
		ll u=q.top().second;
		cout<<u<<" ";
		if(u<=n) vis[u]=true,cnt++;
		else if(!vis[u]) vis[u]=true,Mst+=g[1][u].second;
		Mst+=q.top().first; q.pop();
		if(cnt==n) return Mst;
		for(ll i=0;i<g[u].size();i++){
			ll v=g[u][i].first,w=g[u][i].second;
			if(!vis[v]&&dis[v]>w){
				dis[v]=w;
				q.push({dis[v],v});
			}
		}
	}
	return Mst;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(ll i=1,cost;i<=k;i++){
		cin>>cost;
		for(ll j=1,w;j<=n;j++){
			cin>>w;
			/*for(ll k=1;k<=n;k++){
				g[j].push_back({k,cost+w});
				g[k].push_back({j,cost+w});
			}*/
			g[j].push_back({n+i,cost});
			g[n+i].push_back({j,w});
		}
	}
	//for(ll i=1;i<=n;i++)
	//	sort(g[i].begin(),g[i].end());
	cout<<prim();
	return 0;
}