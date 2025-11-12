#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=7000010 ;
ll f[10010] ;
ll n,m;
struct T2{
	ll u,v,w ;
} p[N],pp[N] ; 
bool cmp(T2 x,T2 y) {
	return x.w<y.w ;
}
ll fd(ll x) {
	if(x==f[x]) return x;
	else return f[x]=fd(f[x]) ;
}
ll cnt ;
ll k;
ll pf[100] ;
ll ans;
ll a[12][10010] ;
ll c[20] ;
void fil() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout) ;
}
ll mx ;
int main() {
	fil() ;
	pf[0]=1;
	for(int i=1;i<=40;i++) pf[i]=pf[i-1]*2 ;
	scanf("%lld%lld%lld",&n,&m,&k) ;
	for(int i=1;i<=m;i++) {
		ll u,v,w ;
		scanf("%lld%lld%lld",&u,&v,&w) ;
		p[i].u=u;
		p[i].v=v;p[i].w=w ;
	}
	sort(p+1,p+m+1,cmp) ;
	for(int i=1;i<=n;i++) f[i]= i;
	for(int i=1;i<=m;i++) {
		ll x=fd(p[i].u),y=fd(p[i].v) ;
		if(x!=y) {
			f[x]=y ;
			p[++cnt]=p[i] ;
		}
	}
	assert(cnt==n-1) ;
//	printf("\n" ) ;
//	for(int i=1;i<=n-1;i++) {
//		printf("%lld %lld %lld \n",p[i].u,p[i].v,p[i].w) ;
//	}
	for(int i=1;i<=k;i++) {
		scanf("%lld",&c[i]) ;
		for(int j=1;j<=n;j++) {
			scanf("%lld",&a[i][j]) ;
		}
	}
//	printf("YES\n") ;
	for(int i=1;i<=n-1;i++) {
		ans+=p[i].w ;
	}
	mx=p[n-1].w ;
//	printf("%lld\n",ans) ;
	for(int i=0;i<(1<<k);i++) {
		ll nwans=0 ;cnt=n-1;
		ll pointsum=0;
		for(int j=1;j<=n-1;j++) pp[j]=p[j] ;
		for(int j=1;j<=k;j++) {
			if(i&pf[j-1]) {
				for(int o=1;o<=n;o++) {
					if(a[j][o]>mx) continue ;
					cnt++;
					pp[cnt].u=j+n;
					pp[cnt].v=o;
					pp[cnt].w=a[j][o] ;
				}
				nwans+=c[j] ;
				pointsum++;
			}
		}
//		printf("	%lld\n",nwans) ;
		for(int j=1;j<=n+k;j++) f[j]= j;
		sort(pp+1,pp+cnt+1,cmp) ;
		ll cntt=0;
		
		for(int j=1;j<=cnt;j++) {
			ll x=fd(pp[j].u),y=fd(pp[j].v) ;
			if(x!=y) {
				f[x]=y ;
				pp[++cntt]=pp[j] ;
			}
			if(cntt==n+pointsum-1) break ;
		}
//		assert(cntt==n+pointsum-1) ;
		if(cntt!=n+pointsum-1) continue ;
		for(int j=1;j<=n+pointsum-1;j++) {
			nwans+=pp[j].w ;
		}
		ans=min(ans,nwans) ;
	}
	printf("%lld",ans) ;
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
