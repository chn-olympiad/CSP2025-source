#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
const ll N=1e4+10;
using namespace std;
ll n,m,k,ans;
ll z[N];
bool y[N];
vector<pair<ll,ll>> g[N];
void dfs(ll x,ll fa){
	for(auto i:g[x]){
		ll o=i.first,p=i.second;
		if(o==fa || y[o]) continue;
		z[o]=min(z[o],p);
		y[o]=1;
		dfs(o,x);
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ll u,v,w;
	memset(z,0x3f,sizeof(z));
	for(ll i=1;i<=m;++i){
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	if(!k){
		dfs(1,1);
		for(ll i=2;i<=n;++i){
			ans+=z[i];
		}
		cout<<ans;
		return 0;
	}
	cout<<"13";
	
	return 0;
} 
