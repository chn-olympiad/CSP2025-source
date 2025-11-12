#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e6+7;
struct nd{
	ll w,v,u;
};
ll n,m,k,ans=0;
nd g[10*M];
ll id=0,cnt=0,ck=0;
ll f[M*5],c[15],vis[M];
ll fid(ll x){
	if(f[x]==x)return x;
	return f[x]=fid(f[x]);
}
void mk(ll x,ll y){
	f[fid(x)]=fid(y);
	return ;
}
bool cmp(nd a,nd b){
	if(a.u>n&&b.u<=n)return a.w+c[a.u-n]<b.w;
	else if(b.u>n&&a.u<=n)return b.w+c[b.u-n]<a.w;
	else if(a.u>n&&b.u>n)return a.w+c[a.u-n]<b.w+c[b.u-n];
	return a.w<b.w;
}
void slove(){
	for(ll i=1;i<=id;i++){
		ll u=g[i].u,v=g[i].v,w=g[i].w;
		if(fid(u)==fid(v))continue;
		cnt++;
		mk(fid(u),fid(v));	
		ans+=w;
		if(u>n&&vis[u-n]!=1){
			vis[u-n]=1;
			ck++;
		}
		if(cnt==n+ck-1){
			return ;
		}
	}
}
int main(){
	freopen("road4.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=n+k;i++)f[i]=i;
	for(ll i=1;i<=m;i++){
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		id++;
		g[id].v=v;
		g[id].u=u;
		g[id].w=w;
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(ll j=1;j<=n;j++){
			ll val;
			scanf("%lld",&val);
			id++;
			g[id].u=n+i;
			g[id].v=j;
			g[id].w=val;
		}
	}
	sort(g+1,g+1+id,cmp);
	slove();
	for(ll i=1;i<=k;i++){
		if(vis[i]==1)ans+=c[i];
	}
	printf("%lld",ans);
	return 0;
}
