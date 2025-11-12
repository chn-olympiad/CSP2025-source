//Author: mairuisheng
//#pragma GCC optimize(3)
#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char s;
	s=getchar();
	while(s<48||s>57)
	{
		if(s=='-')f=-f;
		s=getchar();
	}
	while(s>47&&s<58)
	{
		x=(x<<3)+(x<<1)+s-48;
		s=getchar();
	}
	return x*f;
}
constexpr int N=1e4+20,K=11,M=2e6+1;
struct Edge
{
	int xx,yy,val;
}ed[M];
int n,m,k;
int c[K],a[K][N],f[N],num[N],cnt[K];
bool Cmp(Edge x,Edge y)
{
	return x.val<y.val;
}
int Find(int x)
{
	return x==f[x]?x:f[x]=Find(f[x]);
}
void Work1()
{
	int i,tot=0,fx,fy,ans=0;
	for(i=1;i<=n;++i)f[i]=i;
	sort(ed+1,ed+1+m,Cmp);
	for(i=1;i<=m;++i)
	{
		fx=Find(ed[i].xx);
		fy=Find(ed[i].yy);
		if(fx!=fy)
		{
			f[fx]=fy;
			ans+=ed[i].val;
			if(++tot==n-1)
			{
				printf("%lld\n",ans);
				exit(0);
			}
		}
	}
}
void Work2()
{
	int i,fx,fy,ans=0,j;
	for(i=1;i<=k;++i)
	{
		for(j=1;j<=n;++j)
		{
			ed[++m].xx=i+n;
			ed[m].yy=j;
			ed[m].val=c[i]+a[i][j];
		}
	}
	for(i=1;i<=n+k;++i)f[i]=i;
	for(i=1;i<=n;++i)num[i]=1;
	sort(ed+1,ed+1+m,Cmp);
	for(i=1;i<=m;++i)
	{
		fx=Find(ed[i].xx);
		fy=Find(ed[i].yy);
		if(fx!=fy)
		{
			if(ed[i].xx>n)
			{
				if(cnt[ed[i].xx-n]>0)ans-=c[ed[i].xx-n];
				++cnt[ed[i].xx-n];
			}
			else if(ed[i].yy>n)
			{
				if(cnt[ed[i].yy-n]>0)ans-=c[ed[i].yy-n];
				++cnt[ed[i].yy-n];
			}
			f[fx]=fy;
			num[fy]+=num[fx];
			ans+=ed[i].val;
			if(num[fy]==n)break;
		}
	}
	for(i=1;i<=k;++i)
	{
		if(cnt[i]&1)ans-=c[i];
	}
	printf("%lld",ans);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	int i,u,v,w,j;
	for(i=1;i<=m;++i)
	{
		u=read();
		v=read();
		w=read();
		ed[i].xx=u;
		ed[i].yy=v;
		ed[i].val=w;
	}
	for(i=1;i<=k;++i)
	{
		c[i]=read();
		for(j=1;j<=n;++j)a[i][j]=read();
	}
	if(k==0)Work1();
	else Work2();
	return 0;
}
