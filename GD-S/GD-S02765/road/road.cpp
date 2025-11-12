#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
inline int read()
{
	ll s=0,p=1;
	char c=getchar();
	while(!(c>='0'&&c<='9'||c=='-')) c=getchar();
	if(c=='-') p=-1,c=getchar();
	while(c>='0'&&c<='9') s=s*10+(c-'0'),c=getchar();
	return s*p;
}
const ll MAXN=1e4+5;
ll n,m,k,c[15],a[15][MAXN],F[MAXN+10],ans=1e16;
bool chs[MAXN];
struct node
{
	ll u,v,w;
	bool operator < (const node &t) const {return w<t.w;}
};
vector<node> G,edge;
ll Find(ll x)
{
	if(F[x]==x) return x;
	return F[x]=Find(F[x]);
}
void merge(ll x,ll y)
{
	Find(x),Find(y);
	F[F[y]]=F[x];
}
ll calc(ll s)
{
	ll L=n;
	edge=G;
	for(ll i=1;i<=k;i++)
		if(chs[i])
		{
			L++;
			for(ll j=1;j<=n;j++) edge.pb({L,j,a[i][j]});
		}
	sort(edge.begin(),edge.end());
	for(ll i=1;i<=L;i++) F[i]=i;
	L--;
	for(auto u:edge)
		if(Find(u.u)!=Find(u.v))
		{
			s+=u.w;
			merge(u.u,u.v);
			L--;
			if(!L) return s;
		}
}
void dfs(ll d,ll sum)
{
	if(sum>ans) return;
	if(d>k)
	{
		ans=min(ans,calc(sum));
		return;
	}
	chs[d]=false;
	dfs(d+1,sum);
	chs[d]=true;
	dfs(d+1,sum+c[d]);
}
void init()
{
	edge=G;
	sort(edge.begin(),edge.end());
	G.clear();
	for(ll i=1;i<=n;i++) F[i]=i;
	ll cnt=0;
	for(auto u:edge)
		if(Find(u.u)!=Find(u.v))
		{
			G.pb(u);
			merge(u.u,u.v);
			cnt++;
			if(!cnt==n-1) return;
		}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(ll i=1;i<=m;i++) G.pb({read(),read(),read()});
	for(ll i=1;i<=k;i++)
	{
		c[i]=read();
		for(ll j=1;j<=n;j++) a[i][j]=read();
	}
	init();
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
