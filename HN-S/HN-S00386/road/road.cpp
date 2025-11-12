#include<bits/stdc++.h>
using namespace std;
const int N=5*1e4+5;
struct edge{
	int dis,u;
};
struct node{
	int u,v;
	friend bool operator < (node x,node y){
		return x.u>y.u;
	}
};
vector<edge> e[N];
priority_queue<node> q;
int dis[N],vis[N];
inline void dij(int s,int n){
	q.push({0,s});
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().u,v=q.top().v;
		q.pop();
		if(vis[v]) continue;
		vis[v]++;
		for(auto i:e[v]){
			if(dis[i.dis]>dis[v]+i.u&&(!vis[i.dis])){
				dis[i.dis]=dis[v]+i.u;
				q.push({dis[i.dis],i.dis});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
		}
	}
	int ans=INT_MIN;
	for(int i=1;i<=n;i++){
		dij(i,n);
		int summ=0;
		for(int i=1;i<=n;i++) summ+=vis[i];
		ans=min(summ,ans);
	}
	cout<<ans;
	return 0;
}
