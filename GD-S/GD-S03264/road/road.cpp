#include<bits/stdc++.h>
#define ll unsigned int 
#define ull unsigned long long 
#define ygkg putchar(' ')
#define endl putchar('\n')
const ull inf=1e16;
const ll mod=998244353;
namespace io
{
	template<typename L>
	void in(L &x)
	{
		x=0;bool f=false;char ch=getchar();
		while(!isdigit(ch)) f=ch=='-',ch=getchar();
		do{x=(x<<3)+(x<<1)+(ch^48);}while(isdigit(ch=getchar()));
		if(f) x=-x;
	}
	template<typename L>
	void _out(L x){if(x) _out(x/10),putchar((x%10)^48);}
	template<typename L>
	void out(L x){_out(x>0?x:(x?(putchar('-'),-x):(putchar('0'),0))),endl;}
}
using namespace io;
using namespace std;
struct Edge{ll u,v,w;}es[1000015],e[110015];
bool cmp(Edge x,Edge y){return x.w<y.w;}
ll cnt;
ll fa[10115];
ll fd(ll u){return fa[u]==u?u:fa[u]=fd(fa[u]);}
ll n,m,k;
ll c[15],val;
bool f[15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	in(n),in(m),in(k);
	for(ll i=1;i<=m;++i)
		in(es[i].u),in(es[i].v),in(es[i].w);
	sort(es+1,es+m+1,cmp);
	for(ll i=1;i<=n;++i) fa[i]=i;
	for(ll i=1;i<=m;++i)
	{
		ll ru=fd(es[i].u),rv=fd(es[i].v);
		if(ru==rv) continue;
		fa[ru]=rv;
		e[++cnt]=es[i];
	}
	for(ll i=1;i<=k;++i)
	{
		in(c[i]);
		for(ll j=1;j<=n;++j) in(val),e[++cnt]={n+i,j,val};
	}
	sort(e+1,e+cnt+1,cmp);
	ull ans=inf;
	for(ll S=0;S<((ll)1<<k);++S)
	{
		ull sum=0;
		for(ll i=1;i<=k;++i)
			if(S&(1<<i-1)) f[i]=true,sum+=c[i];
			else f[i]=false;
		for(ll i=1;i<=n+k;++i) fa[i]=i;
		for(ll i=1;i<=cnt;++i)
		{
			if(e[i].u>n&&!f[e[i].u-n]) continue;
			ll ru=fd(e[i].u),rv=fd(e[i].v);
			if(ru==rv) continue;
			fa[rv]=ru;
			sum+=e[i].w;
		}
		ans=min(ans,sum);
//		cout<<sum<<" ";
	}
	out(ans);
	return 0;
}
