#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn=2e6+10;
struct Edge {
	ll u,v,w;
}edge[maxn],temp[maxn];
ll c[20],a[20][maxn],p[maxn];
ll gen[maxn];
inline ll read(){
	ll ret=0,f=1;char ch=getchar();
	while (ch<'0' || ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline ll find(ll x)
{
	return gen[x]=(gen[x]==x)?(x):(find(gen[x]));
}
inline bool cmp(const Edge x,const Edge y)
{
	return x.w<y.w;
}
inline ll lmin(ll a,ll b)
{
	if (a<b) return a;
	return b;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ll n=read(),m=read(),K=read();
	for (ll i=1;i<=m;++i)
		edge[i].u=read(),
		edge[i].v=read(),
		edge[i].w=read();
	for (ll i=1;i<=K;++i)
	{
		c[i]=read();
		for (ll j=1;j<=n;++j)
			a[i][j]=read();
	}
	
	sort(edge+1,edge+m+1,cmp);
	for (ll i=1;i<=n;++i) gen[i]=i;
	ll num=0,ans=0;
	for (ll i=1;i<=m;++i)
	{
		if (num==n-1) break;
		ll u=edge[i].u,
			v=edge[i].v,
			w=edge[i].w;
		find(u);find(v);
		ll g1=gen[u],g2=gen[v];
		if (g1==g2) continue;
		if (g1>g2) swap(g1,g2);
		gen[g2]=g1;ans+=w;
		temp[++num]=edge[i];
	}
	
	memcpy(edge,temp,sizeof(edge));
	memset(temp,0,sizeof(temp));
	for (ll x=1;x<=(1<<K)-1;++x)
	{
		for (ll i=0;i<=n;++i)
			gen[i]=i,
			p[i]=INT_MAX;
			
		ll t=x,sum=0;
		for (ll i=1;t;++i,t/=2)
		{
			if (t&1^1) continue;
			sum+=c[i];
			for (ll j=1;j<=n;++j)
				p[j]=lmin(p[j],a[i][j]);
		}
		
		for (ll i=1;i<=n;++i)
			temp[i]=(Edge){0,i,p[i]};
		sort(temp+1,temp+n+1,cmp);
		
		ll ss=0,d1=1,d2=1;
		while (ss!=n)
		{
			Edge ttt;
			if (d2>n || edge[d1].w<temp[d2].w)
				ttt=edge[d1],d1++;
			else ttt=temp[d2],d2++;
			
			ll u=ttt.u,
				v=ttt.v,
				w=ttt.w;
			find(u);find(v);
			ll g1=gen[u],g2=gen[v];
			if (g1==g2) continue;
			if (g1>g2) swap(g1,g2);
			gen[g2]=g1;
			sum+=w;ss++;
		}
		ans=lmin(ans,sum);
	}
	printf("%lld ",ans);
} 
