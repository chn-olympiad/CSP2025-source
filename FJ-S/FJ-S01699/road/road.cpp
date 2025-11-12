#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,k,ans;
bool p[10005];
vector<pair<ll,ll>> g[10005];
int a[15][10005],dis[10005];
set<pair<ll,ll>> heap,heap2;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(ll i=0;i<k;i++){
		for(ll j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(ll i=2;i<=n;i++){
		dis[i]=1e9;
	}
	heap.insert({0,1});
	p[1]=true;
	while(!heap.empty()){
		ll u=heap.begin()->second;
		heap.erase(heap.begin());
		for(ll i=0;i<g[u].size();i++){
			ll v=g[u][i].first,w=g[u][i].second;
			if(p[v]==true)continue;
			if(dis[v]>w){
				heap.erase({dis[v],v});
				dis[v]=w;
				p[v]=true;
				heap.insert({dis[v],v});
			}
		}
	}
	for(ll i=2;i<=n;i++){
		ans+=dis[i];
	}
	printf("%lld",ans);
	return 0;
}
