#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=(1e6)+500;
ll n,m,k,fa[maxn],c[maxn],l[20][maxn];
struct node{
	ll u,v,w;
}a[maxn];
bool cmp(node A,node B){
	return A.w<B.w;
}
ll fi(ll x){
	if(fa[x]==x)return x;
	return fa[x]=fi(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld",c+i);
		for(ll j=1;j<=n;j++){
			
			scanf("%lld",&l[i][j]);
		}
	}
	for(ll i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(a+1,a+m+1,cmp);
	ll ans=0;
	for(ll i=1;i<=m;i++){
		if(fi(a[i].u)!=fi(a[i].v)){
			ans+=a[i].w;
			fa[fi(a[i].u)]=fi(a[i].v);
		}
	}printf("%lld",ans);
	return 0;
}
