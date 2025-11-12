#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,x,y,z,k,c[10015],a[10][10015],f[10015];
ll ans=0;
struct node{
	ll v;
	ll w;
	};
vector<node>e[10005];
void dfs(ll u,ll fa){
	f[u]=1;
	ll minn=10000000000000005;
	ll to;
	for(ll i=1;i<=(ll)(e[u].size());i++){
		node V=e[u][i];
		if(V.v==fa||!V.v)continue;
		ll tp=minn;
		minn=min(minn,V.w);
		if(tp!=minn){
			to=V.v;
			}
		}
	ans+=minn;
	if(!f[to])dfs(to,u);
	}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
		}
	for(ll j=1;j<=k;j++){
		cin>>c[j];
		for(ll i=1;i<=n;i++){
			cin>>a[j][i];
			e[n+j].push_back({i,a[j][i]});
			e[i].push_back({n+j,a[j][i]});
			}
		}
	dfs(1,1);
	cout<<ans;
	return 0;
	}
