#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;
typedef long long ll;
const ll maxn=1000007;
struct Edge{
	ll u,v,w;
	bool operator<(Edge &o){return w<o.w;}
}edge[maxn*2];
ll n,m,k,tot,c[maxn],vis[maxn],ans;
struct Dsu{
	ll fa[maxn],siz[maxn];
	void init(ll n){iota(fa+1,fa+1+n,1),fill(siz+1,siz+1+n,1);}
	ll fid(ll x){for(;fa[x]!=x;x=fa[x]=fa[fa[x]]); return x;}
	bool merge(ll x,ll y){
		ll fx=fid(x),fy=fid(y);
		if(fx==fy) return 0;
		if(siz[fx]>siz[fy]) swap(fx,fy);
		fa[fx]=fy,siz[fy]+=siz[fx];
		return 1;
	}
}dsu;
ll MST(void){
	dsu.init(n+k);
	ll res=0;
	for(ll i=1;i<=k;i++)if(vis[i]) res+=c[i];
	for(ll i=1,u,v;i<=tot;i++){
		u=edge[i].u,v=edge[i].v;
		if(u>n&&!vis[u-n]) continue;
		if(dsu.merge(u,v)) res+=edge[i].w;
	}
	return res;
}
int main(void){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++) cin>>edge[i].u>>edge[i].v>>edge[i].w;
	for(ll i=1,x;i<=k;i++){
		cin>>c[i];
		for(ll j=1;j<=n;j++) cin>>x,edge[m+(i-1)*n+j]=Edge{n+i,j,x};
	}
	tot=m+n*k;
	sort(edge+1,edge+1+tot);
	if(k<=5||m*(1<<k)<=150000000){
		ans=1e18;
		for(ll S=0;S<(1<<k);S++){
			for(ll i=1;i<=k;i++) vis[i]=(S>>(i-1))&1;
			//for(ll i=1;i<=k;i++) cout<<vis[i]<<" "; cout<<"\n";
			//ans=min(ans,MST());
			ll res=MST();
			//cout<<res<<"\n";
			ans=min(ans,res);
		}
	}else{
		ans=MST();
		for(ll i=1,res;i<=k;i++){
			vis[i]=1;
			res=MST();
			if(res>ans) vis[i]=0;
			else ans=res;
		}
		for(ll i=1,res;i<=k;i++)if(vis[i]){
			vis[i]=0;
			res=MST();
			if(res>ans) vis[i]=1;
			else ans=res;
		}
	}
	cout<<ans<<"\n";
	return 0;
}