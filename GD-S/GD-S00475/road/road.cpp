#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,k;
ll const maxn=10100;
ll const maxm=1000000;
struct edge{
	ll u,v,w;
};
edge p[maxn+1];
ll cnt;
edge d[maxm+1];
ll dnt;
ll ans;
namespace Kru{
	edge g[maxm+1];
	ll fa[maxn+1];
	ll find(ll a){
		if(fa[a]==a){
			return a;
		}
		return fa[a]=find(fa[a]);
	}
	void kru(){
		for(ll i=1;i<=n;i++){
			fa[i]=i;
		}
		sort(g+1,g+m+1,[](edge a,edge b){
			return a.w<b.w;
		});
		for(ll i=1;i<=m;i++){
			ll u=g[i].u;
			ll v=g[i].v;
			ll w=g[i].w;
			if(find(u)!=find(v)){
				cnt++;
				p[cnt]={u,v,w};
				ans+=w;
				fa[find(u)]=find(v);
			}
		}
	}
}
ll fa[maxn+1];
ll find(ll a){
	if(fa[a]==a){
		return a;
	}
	return fa[a]=find(fa[a]);
}
ll const inf=1e18+7;
ll kru(){
	sort(d+1,d+dnt+1,[](edge a,edge b){
		return a.w<b.w;
	});
	for(ll i=1;i<=n+k;i++){
		fa[i]=i;
	}
	ll ret=0;
	ll dt=0;
	for(ll i=1;i<=dnt;i++){
		ll u=d[i].u;
		ll v=d[i].v;
		ll w=d[i].w;
		if(find(u)!=find(v)){
			ret+=w;
			dt++;
			fa[find(u)]=find(v);
			if(ret>=ans){
				return ret;
			}
			if(dt==n+k-1){
				return ret;
			}
		}
	}
	return ret;
}
ll c[11];
ll a[11][maxn+1];
ll read(){
	ll res=0;
	char in=getchar();
	while(in<'0'||in>'9'){
		in=getchar();
	}
	while(in>='0'&&in<='9'){
		res=res*10+in-'0';
		in=getchar();
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		u=read(),v=read(),w=read();
		Kru::g[i]={u,v,w};
	}
	for(ll i=1;i<=k;i++){
		c[i]=read();
		for(ll j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	Kru::kru();
	ll w=1<<k;
	for(ll t=0;t<w;t++){
		dnt=cnt;
		for(ll i=1;i<=cnt;i++){
			d[i]=p[i];
		}
		ll ret=0;
		for(ll i=1;i<=k;i++){
			if((t>>(i-1))&1){
				ret+=c[i];
			}
		}
		if(ret>=ans){
			continue;
		}
		for(ll i=1;i<=k;i++){
			if((t>>(i-1))&1){
				for(ll j=1;j<=n;j++){
					if(a[i][j]>=ans){
						continue;
					}
					dnt++;
					d[dnt]={n+i,j,a[i][j]};
				}
			}
		}
		ret+=kru();
		if(ret<ans){
			ans=ret;
		}
	}
	printf("%lld",ans);
	
	
	
	return 0;
}
