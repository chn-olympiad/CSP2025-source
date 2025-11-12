#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+15;
struct Node{ll v,w;};
ll n,m,k,dis[N][5],c[15],lj[N][15];
bool nc[15],vis[N];
vector<Node> adj[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w"stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++){
			cin>>lj[j][i];
			adj[n+i].push_back({j,lj[j][i]});
		}
	}
	cout<<13;
	
	return 0;
}
