#include<bits/stdc++.h>
using namespace std;
const int MN=1e6+10;
using ll=long long;
ll n,m,k;
set<pair<int,int>> g[MN];
bitset<MN> vis;
ll ans=0x3f3f3f3f3f3f3f3f;
struct dat{
	ll u,v,w;
}e[MN];
map<pair<ll,ll>,ll> mp;
ll top,fa[MN],c[MN];
ll find(int u){
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
ll kk(int k){
	ll cnt=0,ans=0;
	for(int i=1;i<=n+k;i++) fa[i]=i,vis[i]=0;
	for(int i=1;i<=n+k&&cnt<n-1+k;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu!=fv){
			// cout<<e[i].u<<' '<<e[i].v<<' '<<e[i].w<<' '<<c[e[i].u]<<'\n';
			fa[fu]=fv;
			cnt++;
			ans+=e[i].w+c[e[i].u]*(!vis[e[i].u]);
			vis[e[i].u]=1;
			// cout<<e[i].u<<' '<<e[i].v<<'\n';
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,c;
		cin>>u>>v>>c;
		g[u].insert({v,c});
		g[v].insert({u,c});
		e[++top]={u,v,c};
		// cout<<u<<' '<<v<<' '<<c<<'\n';
	}
	for(ll i=1;i<=k;i++){
		cin>>c[i+n];
		//cout<<i+n<<' '<<c[i+n]<<'\n';
		for(ll j=1;j<=n;j++){
			ll x;
			cin>>x;
			g[i+n].insert({j,x});
			g[j].insert({i+n,x});
			e[++top]={i+n,j,x};
			// cout<<i<<' '<<j<<' '<<x<<'\n';
		}
	}
	sort(e+1,e+1+top,[](dat a,dat b){
		return a.w+c[a.u]<b.w+c[b.u];
	});
	cout<<kk(k);
	return 0;
}
