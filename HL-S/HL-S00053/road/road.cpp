#include <bits/stdc++.h>
//#define int long long
using namespace std;
constexpr int M=15,N=1e4+5;
int n,m,k,ans;
int vis[N];
struct Edge{
	int v,w;
};
vector<Edge>g[N];
struct Node{
	int v,w;
	friend bool operator < (Node a,Node b){
		return a.w > b.w;
	}
};
priority_queue<Node>q;
void Prim(){
	vis[1]=1;
	for(int u=2;u<=n;u++){
		int minn=INT_MAX;
		vis[u]=1;
		for(auto temp:g[u]){
			int v=temp.v,w=temp.w;
			if(vis[v]){
				minn=min(minn,w);
			}
		}
		ans+=minn;
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	Prim();
	cout<<ans;
	return 0;
}
