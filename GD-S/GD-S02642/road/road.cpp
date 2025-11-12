#include<bits/stdc++.h>
#define ll long long
using namespace std; 
ll n,m,k;
struct A
{
	ll x,y,v;
}e[1500000];
ll c[500];
ll tot;
ll v[1500000];
ll read()
{
	char ch=getchar();
	ll v=1;
	while(!('0'<=ch&&ch<='9'))
	{
		if(ch=='-') v=-1;
		ch=getchar();
	}
	ll x=0;
	while('0'<=ch&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*v;
}
ll a[15][15000];
bool cmp(A x,A y)
{
	return x.v<y.v;
}
ll t[150000];
ll find(ll x)
{
	if(x==t[x])
	{
		return x;
	}
	return t[x]=find(t[x]);
}
void sol1()
{
	for(ll i=1;i<=n;i++) t[i]=i; 
	ll bian=0,ans=0;
	for(ll i=1;i<=m;i++)
	{
		ll fx=find(e[i].x);
		ll fy=find(e[i].y);
		if(fx==fy) continue;
		ans+=e[i].v;
		bian++;
		t[fx]=fy;
		if(bian>=n-1) break;
	}
	printf("%lld",ans);
}
ll bi[2000][2000];
void sol2()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			bi[i][j]=1000000000000;
		}
	}
	for(int i=1;i<=m;i++)
	{
		bi[e[i].x][e[i].y]=min(e[i].v,bi[e[i].x][e[i].y]);
		bi[e[i].y][e[i].x]=min(e[i].v,bi[e[i].y][e[i].x]);
	}
	for(ll i=1;i<=k;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			for(ll w=1;w<=n;w++)
			{
				bi[i][j]=min(bi[i][j],a[i][j]+a[i][w]);
				bi[j][i]=min(bi[j][i],a[i][j]+a[i][w]);
			}
		}
	}
	m=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			e[++m]={i,j,bi[i][j]};
		}
	}
	sort(e+1,e+1+m,cmp);
	for(ll i=1;i<=n;i++) t[i]=i;
	ll bian=0,ans=0;
	for(ll i=1;i<=m;i++)
	{
		ll fx=find(e[i].x);
		ll fy=find(e[i].y);
		if(e[i].x==e[i].y) continue;
		if(fx==fy) continue;
		ans+=e[i].v;
		bian++;
		t[fx]=fy;
		if(bian>=n-1) break;
	}
	printf("%lld",ans);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=m;i++)
	{
		e[i].x=read(),e[i].y=read(),e[i].v=read();
	}
	sort(e+1,e+1+m,cmp);
	ll tmp=0;
	for(ll i=1;i<=k;i++)
	{
		c[i]=read();
		for(ll j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
	if(k==0)
	{
		sol1();
		return 0;
	}
	else if(n<=1000)
	{
		sol2();
	}
	else
	{
		sol1();
	}
}
