#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=1e4+20,M=1e6+20;
ll n,m,k,mcnt,ans;
ll c[N],a[20][N],fa[N];
struct Node{
	ll u,v,w;
	bool operator>(const Node &x)const{return w>x.w;}
	bool operator<(const Node &x)const{return w<x.w;}	 
}e[M*3];

void add(ll u,ll v,ll w){mcnt++;e[mcnt].u=u,e[mcnt].v=v,e[mcnt].w=w;}

ll find(ll x){return fa[x]=(x==fa[x]?x:find(fa[x]));}

void kk(){
	for(ll i=1;i<=n+k;i++)fa[i]=i;
	sort(e+1,e+1+mcnt);
	for(ll i=1;i<=mcnt;i++){
		ll u=e[i].u,v=e[i].v;
		ll fu=find(u),fv=find(v);
		if(fu==fv)continue;
		fa[fu]=fv;
		ans+=e[i].w;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1,u,v,w;i<=m;i++)scanf("%lld%lld%lld",&u,&v,&w),add(u,v,w);
	for(ll i=1;i<=k;i++){
		scanf("%lld",c+i);
		for(ll j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(j==1)add(n+i,j,a[i][j]+c[i]);
			else add(n+i,j,a[i][j]);
		}
	}
	kk();
	
	printf("%lld",ans);
	
	return 0;
}
