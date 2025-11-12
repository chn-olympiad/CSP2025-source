#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edg
{
	int u,v,w;
};
priority_queue<edg>e;
bool operator <(const edg &a,const edg &b)
{
	return a.w>b.w;
}
int fa[10005],n,m,k,ans,sum[10005],c[15],a[15][10005];
bool cze=1;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		u=read();v=read();w=read();
		e.push({u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		if(c[i]) cze=0;
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	if(cze)
	{
		int nn=n+k;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				e.push({n+i,j,a[i][j]});
		for(int i=1;i<=nn;i++)
		{
			fa[i]=i;
			sum[i]=1;
		}
		while(!e.empty())
		{
			u=find(e.top().u);v=find(e.top().v);w=e.top().w;
			e.pop();
			if(u==v) continue;
			fa[u]=v;
			sum[v]+=sum[u];
			ans+=w;
			if(sum[v]==nn) break;
		}
		printf("%lld\n",ans);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			fa[i]=i;
			sum[i]=1;
		}
		while(!e.empty())
		{
			u=find(e.top().u);v=find(e.top().v);w=e.top().w;
			e.pop();
			if(u==v) continue;
			fa[u]=v;
			sum[v]+=sum[u];
			ans+=w;
			if(sum[v]==n) break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
