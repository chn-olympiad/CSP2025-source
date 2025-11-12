#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4,M=1e6,K=10,INF=1e18;
struct edge{
	ll u,v,w;
}e[3*N+5],ee[15*N],eee[N+5];
ll n,m,k;
ll tot=1,tott=1,cnte;
ll c[K+5],v[K+5][N+5];
ll fa[2*N+5];
ll ans;
void add(ll u,ll v,ll w){
	e[tot].u=u;
	e[tot].v=v;
	e[tot].w=w;
	tot++;
	return;
}
void addd(ll u,ll v,ll w){
	ee[tott].u=u;
	ee[tott].v=v;
	ee[tott].w=w;
	tott++;
	return;
}
bool cmp(edge l1,edge l2){
	return l1.w<l2.w;
}
ll find(ll x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=n;i++) fa[i]=i;
	for(ll i=1;i<=m;i++){
		ll x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		add(x,y,z);
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(ll j=1;j<=n;j++) scanf("%lld",&v[i][j]);
	}
	sort(e+1,e+m+1,cmp);
	for(ll i=1;i<=m;i++){
		ll u=e[i].u,v=e[i].v;
		u=find(u),v=find(v);
		if(u==v) continue;
		addd(e[i].u,e[i].v,e[i].w);
		eee[++cnte]=ee[tott-1];
		ans+=e[i].w;
		fa[u]=v;
	}
	for(ll i=1;i<(1<<k);i++){
		tott=n;
		for(ll j=1;j<=2*n;j++) fa[j]=j;
		for(ll j=1;j<=cnte;j++) ee[j]=eee[j];
		ll anss=0;
		for(ll j=0;j<k;j++){
			ll x=j+1,num=((i>>j)&1);
			if(num){
				for(ll k=1;k<=n;k++) addd(n+x,k,v[x][k]);
				anss+=c[x];
			}
		}
		sort(ee+1,ee+tott,cmp);
//		cout<<endl;
//		for(ll j=1;j<tott;j++) cout<<ee[j].u<<" "<<ee[j].v<<" "<<ee[j].w<<endl;
//		cout<<endl;
//		continue;
		for(ll j=1;j<tott;j++){
			ll u=ee[j].u,v=ee[j].v;
//			cout<<e[j].u<<" "<<e[j].v<<" "<<e[j].w<<endl;
			u=find(u),v=find(v);
			if(u==v) continue;
			anss+=e[j].w;
			fa[u]=v;
		}
//		cout<<anss<<endl;
		ans=min(ans,anss);
	}
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
