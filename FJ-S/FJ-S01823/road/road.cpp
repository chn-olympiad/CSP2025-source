//rp++
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Inf = 2e18;
const ll M = 2e6+5;
const ll N = 1e4+5;
const ll K = 20;
struct EDGE{ll u,v,w;}edge[M];
ll cost[K],valid[K],fa[N+K];
ll n,m,k,tot,times;
ll ans=Inf,res;
void add(ll u,ll v,ll w){
	edge[++tot]={u,v,w};
}
bool compare(EDGE A,EDGE B){
	return A.w<B.w;
}
ll Find(ll x){
	if(x==fa[x]) return x;
	return fa[x]=Find(fa[x]);
}
void kruskal(){
	ll cnt=0;
	for(ll i=1;i<=tot;i++){
		ll u=edge[i].u;
		ll v=edge[i].v;
		if(u>n&&(!valid[u-n])) continue;
		ll r1=Find(u),r2=Find(v);
		if(r1!=r2){
			cnt++,res+=edge[i].w;
			fa[r1]=r2;
		}
		if(res>ans) return;
		if(cnt==n+times-1){
			ans=min(ans,res);
			return;
		}
	}
}
void solve(){
	for(ll i=0;i<(1<<k);i++){
		for(ll j=1;j<=k;j++) valid[j]=0;
		for(ll j=1;j<=k+n;j++) fa[j]=j;
		times=res=0;
		for(ll j=1;j<=k;j++){
			if((i>>(j-1))&1) valid[j]=1,res+=cost[j],times++;
		}
		kruskal();
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(ll i=1;i<=k;i++){
		cin>>cost[i];
		for(ll j=1;j<=n;j++){
			ll w;
			cin>>w;
			add(i+n,j,w);
		}
	}
	sort(edge+1,edge+tot+1,compare);
	solve();
	cout<<ans;
	return 0;
}
