#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll rd() {
	int x=0,f=1; char c=getchar();
	while(c<'0' || '9'<c) {
		if(c=='-') f=-1;
		c=getchar();
	} while('0'<=c && c<='9') {
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	} return x*f;
}
const ll N=1e5+10,NN=8e6+10;
const ll inf=1e16;
struct node {
	ll u,v,w;
} b[NN],a[N*100];
bool cmp(node x,node y)
{ return x.w<y.w; }
ll f[N],n,m,k,c[11][N],w[11];
ll dis[1010][1010];
ll gf(ll x) {
//	printf("%lld ",x);
	if(x==f[x]) {
		return x;
	} return f[x]=gf(f[x]);
}
void mg(ll x,ll y) {
	x=gf(x); y=gf(y);
	if(x==y) {
		return ;
	} f[x]=y;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(); m=rd(); k=rd();
//	cout<<n<<endl;
	for(ll i=1;i<=n;i++) {
		f[i]=i;
	} for(ll i=1;i<=m;i++) {
		ll u=rd(),v=rd(),w=rd();
		b[i].u=u; b[i].v=v; b[i].w=w;
	} 
	for(ll i=1;i<=k;i++) {
		w[i]=rd();
		for(ll j=1;j<=n;j++) {
			ll x=rd();
			c[i][j]=x;
		}
	}
	if(n<=1000 || k==0) {
		for(ll i=1;i<=n;i++) {
			for(ll j=1;j<=n;j++) {
				dis[i][j]=inf;
			} dis[i][i]=0;
		}
		for(ll i=1;i<=n;i++) {
			for(ll j=1;j<=n;j++) {
				for(ll o=1;o<=k;o++) {
					if(i==j) continue ;
					dis[i][j]=min(dis[i][j],(ll)(c[o][i]+c[o][j]+w[o]));
				}
				if(i==j) continue ;
				m++;
				b[m].u=i;
				b[m].v=j;
				b[m].w=dis[i][j];
			}
		}
		sort(b+1,b+m+1,cmp);
//		printf("%lld\n",m);
		ll res=0;
		for(ll i=1;i<=m;i++) {
			ll u=gf(b[i].u);
			ll v=gf(b[i].v);
			if(u!=v) {
				res+=b[i].w;
				mg(u,v);
			}
		} printf("%lld",res);
	} else {
		ll cnt=0;
		for(ll i=1;i<=m;i++) {
			ll u=gf(b[i].u),v=gf(b[i].v);
			if(u!=v) {
				mg(u,v);
				cnt++;
				a[cnt].u=u;
				a[cnt].v=v;
				a[cnt].w=b[i].w*1ll;
			}
		}
		ll res=0;
		for(ll i=1;i<=cnt;i++) {
			ll sum=a[i].w,u=a[i].u,v=a[i].v;
			for(ll j=1;j<=k;j++) {
				sum=min(sum,(ll)(c[j][u]+c[j][v]+w[j]));
			} res+=sum;
		} printf("%lld",res);
	}
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
