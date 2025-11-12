#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+5,M=1e6+5;
ll n,m,k,ans,fa[N];
ll c[15],a[15][N];
bool flag=true;
struct edge{
	ll u,v,w;
}e[M<<1];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
ll getfa(ll x){
	if(x==fa[x]) return fa[x];
	return fa[x]=getfa(fa[x]);
}
void solve1(){
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		ll u=e[i].u;
		ll v=e[i].v;
		ll w=e[i].w;
		ll fu=getfa(u);
		ll fv=getfa(v);
		if(fu==fv) continue;
		ans+=w;fa[fu]=fv;
	}
}
void solve2(){
	for(int i=1;i<=k;i++){
		fa[n+i]=n+i;
		for(int j=1;j<=n;j++)
			e[++m]={n+i,j,a[i][j]};
	}sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		ll u=e[i].u;
		ll v=e[i].v;
		ll w=e[i].w;
		ll fu=getfa(u);
		ll fv=getfa(v);
		if(fu==fv) continue;
		ans+=w;fa[fu]=fv; 
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]) flag=false;
		for(int j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	}if(k==0) solve1();
	else if(flag) solve2();
	else solve1();
	printf("%lld",ans);
	return 0;
}
