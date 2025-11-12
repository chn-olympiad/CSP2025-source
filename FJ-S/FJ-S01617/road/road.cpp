#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 10005
struct data{
	ll v;
	ll w;
};
vector<data> adj[maxn];
ll n,m,k;

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		adj[u].v.push_back(v);
		adj[v].v.push_back(u);
		adj[u].w.push_back(w);
		adj[v].w.push_back(w);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
