#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
const int M=1e6+7;
int n,m,k,ans;
int dis[N];
bool vis[N];
int vil[15];
struct node{
	int v;
	int w;
	bool operator < (const _node __&x, const _node __y) const
		return __x.w < __y.w; 
	}
};
vector<node> G[M];
void add(int u,int v,int w){
	G[u].push_back({v,w});
	G[v].push_back({u,w});
}
priority_queue<node> q;
void dij(int s){
	for(int i=1;i<=n;i++) dis[i]=1e15;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty())_{
		node tmp=q.top();
		q.pop();
		for(int i=0;i<G[tmp].size();i++){
			int v=G[i].v;
			int w=G[i].w;
			if(vis[v]) continue;
			vis[v]=true;
			if(dis[v]>dis[tmp.v]+w) {
				dis[v]=dis[tmp.v]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=k;i++) cin>>vil[i];
	dis(1);
	for(int i=1;i<=n;i++) ans=max(ans,dis[i]);
	cout<<ans;
	return 0;
}
