#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,c[11],a[11][10001],fa[12001],sum=0,ans=2e18,ssum=0;
bool flag;
struct node
{
	ll u,v,w,id;
}e[1200001];
inline ll read()
{
	ll s=0,f=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) s=(s<<3)+(s<<1)+(ch^48);
	return f?-s:s;
}
inline bool cmp(node x,node y)
{
	return x.w<y.w;
}
inline bool cmpp(node x,node y)
{
	return x.id<y.id;
}
ll find(ll x)
{
	while(x!=fa[x]) return fa[x]=find(fa[x]);
	return x;
}
inline void deal(ll x)
{
	for(ll i=1;i<=k;i++)
	{
		if((x>>(i-1))&1)
		{
			sum+=c[i];
			for(ll j=1;j<=n;j++)
			{
				m++;
				e[m].u=n+i;
				e[m].v=j;
				e[m].w=a[i][j];
				e[m].id=m;
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(ll i=1;i<=m;i++)
	{
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
		e[i].id=i;
	}
	for(ll i=1;i<=k;i++)
	{
		c[i]=read();
		if(c[i]) flag=1;
		for(ll j=1;j<=n;j++) a[i][j]=read();
	}
	if(!flag)
	{
		for(ll i=1;i<=n+k;i++) fa[i]=i;
		for(ll i=1;i<=k;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				m++;
				e[m].u=n+i;
				e[m].v=j;
				e[m].w=a[i][j];
			}
		}
		n+=k;
		sort(e+1,e+m+1,cmp);
		for(ll i=1;i<=m;i++)
		{
			ll u=e[i].u,v=e[i].v;
			ll fu=find(u),fv=find(v);
			if(fu==fv) continue;
			fa[fv]=fu;
			sum+=e[i].w;
		}
		cout<<sum;
		return 0;
	}
	ll kk=1;
	for(ll i=1;i<=k;i++) kk*=2;
	for(ll i=0;i<kk;i++)
	{
		sum=0;
		ssum=0;
		for(ll i=1;i<=n+k;i++) fa[i]=i;
		ll tn=n,tm=m;
		deal(i);
		n+=k;
		sort(e+1,e+m+1,cmp);
		for(ll i=1;i<=m;i++)
		{
			ll u=e[i].u,v=e[i].v;
			ll fu=find(u),fv=find(v);
			if(fu==fv) continue;
			fa[fv]=fu;
			sum+=e[i].w;
			ssum++;
			if(ssum==n-1) break;
		}
		sort(e+1,e+m+1,cmpp);
		ans=min(ans,sum);
		n=tn;
		m=tm;
	}
	cout<<ans;
	return 0;
}
