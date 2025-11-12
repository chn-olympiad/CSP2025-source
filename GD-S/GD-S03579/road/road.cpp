#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=1e4;
const int M=1e6;
const int K=10;
bool b[N+100];
ll fa[N+100];
ll cc[K+5][N+100];
ll n,m,k,cnt=0,ans=0,pp;
struct s {
	ll x;
	ll y;
	ll w;
} a[10*M];
ll find(ll x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(s x,s y) {
	return x.w<y.w;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1,u,v,w; i<=m; i++) {
		scanf("%lld%lld%lld",&u,&v,&w);
		a[++cnt].x=u;
		a[cnt].y=v;
		a[cnt].w=w;
	}
	for(ll i=1,c; i<=k; i++) {
		scanf("%lld",&c);
		for(ll j=1; j<=n; j++) scanf("%lld",&cc[i][j]);
		for(ll j=1; j<=n; j++) {
			for(ll l=j+1; l<=n; l++) {
				a[++cnt].x=j;
				a[cnt].y=l;
				a[cnt].w=c+cc[i][j]+cc[i][l];
			}
		}
	}
	for(ll i=1; i<=n; i++) fa[i]=i;
	sort(a+1,a+cnt+1,cmp);
	for(ll i=1; i<=n-1; i++) {
		for(ll j=1; j<=cnt; j++) {
//		cout<<a[j].x<<" "<<a[j].y<<" "<<a[j].w<<endl;
			ll fx=find(a[j].x);
			ll fy=find(a[j].y);
			if(fx!=fy) {
				fa[fy]=fx;
				ans+=a[j].w;
				break;
			}
			
		}
	}
	printf("%lld",ans);
	return 0;
}
