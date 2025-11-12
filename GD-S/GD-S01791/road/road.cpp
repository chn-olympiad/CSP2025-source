#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace qwq {
const int N=10010,M=1e6+10,K=11;
const ll INFll=0x3f3f3f3f3f3f3f3f;
int n,m,k,ln,lq;
struct NODE {int u,v,w;} p[M],q[N*(K+1)],tmp[N*(K+1)],qq[N],r[K][N];
int c[K],a[K][N],fa[N*2];
int fd(int u) {return u==fa[u]?u:fa[u]=fd(fa[u]);}
void main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].w);
	sort(p+1,p+1+m,[&](NODE x,NODE y) {return x.w<y.w;});
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		int u=fd(p[i].u),v=fd(p[i].v);
		if(u!=v) fa[u]=v,qq[++lq]=p[i];
	}
	for(int i=1;i<=k;i++) {
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]),r[i][j]={i+n,j,a[i][j]};
		sort(r[i]+1,r[i]+1+n,[&](NODE x,NODE y) {return x.w<y.w;});
	}
	ll as=INFll;
	for(int s=0;s<1<<k;s++) {
		ln=0;
		for(int i=1;i<=lq;i++) q[++ln]=qq[i];
		ll sm=0;
		for(int i=1;i<=k;i++) if(s>>i-1&1) {
			sm+=c[i]; int lt=0;
			for(int j=1,l=1;j<=n||l<=ln;) {
				if(j<=n&&(l>ln||r[i][j].w<q[l].w)) tmp[++lt]=r[i][j++];
				else tmp[++lt]=q[l++];
			}
			ln=lt;
			for(int i=1;i<=ln;i++) q[i]=tmp[i];
		}
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=ln;i++) {
			int u=fd(q[i].u),v=fd(q[i].v);
			if(u!=v) fa[u]=v,sm+=q[i].w;
		}
		as=min(as,sm);
	}
	printf("%lld\n",as);
}

}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	qwq::main();
}

