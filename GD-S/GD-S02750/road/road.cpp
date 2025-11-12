#include<bits/stdc++.h>
#define ll unsigned long long
#define maxn 200005
using namespace std;
ll n,m,k;
struct Edge{
	ll u,v,w;
	ll t;
};
vector<Edge> vec;
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
ll f[maxn];
ll find(ll u){
	return f[u]==u?u:f[u]=find(f[u]);
}
void merge(ll u,ll v){
	f[find(u)]=find(v);
}
ll kruskal(set<ll> ok){
	ll tot=0, nd=n+ok.size()*2,res=0;
	for(auto e:vec){
		if(find(e.u)!=find(e.v)){
			if((!e.t)||(ok.count(e.t))){
				merge(e.u,e.v);
				res+=e.w;
				tot++;
			}
		}
		if(tot==nd-1)break;
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++){
		ll u,v,w;cin>>u>>v>>w;
		vec.push_back({u,v,w,0});
	}
	ll cnt=n;
	for(ll i=1;i<=k;i++){
		ll c;cin>>c;
		cnt++;
		vec.push_back({cnt,cnt+1,c,i});
		for(ll j=1;j<=n;j++){
			ll w;cin>>w;
			vec.push_back({cnt+1,j,w,i});
		}
		cnt++;
	}
	sort(vec.begin(),vec.end(),cmp);
	ll res=LLONG_MAX;
	for(ll ttt=0;ttt<(1ULL<<k);ttt++){
		set<ll> ok;
		for(ll i=0;i<=k;i++){
			if(ttt>>i&1){
				ok.insert(i+1);
			}
		}
		for(ll i=1;i<=cnt+1;i++)f[i]=i;
		ll ans=kruskal(ok);
//		cerr<<ans<<" ";
		res=min(ans,res);
	}
	cout<<res<<"\n";
	return 0;
} 
