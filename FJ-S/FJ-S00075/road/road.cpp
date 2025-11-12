#include<bits/stdc++.h>
using namespace std;
struct bian
{
	int u,v,w;
}q[2000005];
bool cmp(bian x,bian y)
{
	return x.w<y.w;
}
int a[15][10005],c[15],cp[15];
int n,m,k;
int flaga=0;
int fa[20005];
int find(int x)
{
	if (fa[x]==x)
	{
		return x;
	}
	return fa[x]=find(fa[x]);
}
void hb(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if (fx!=fy)
	{
		fa[fx]=fy;
	}
}
long long ot=LONG_LONG_MAX;
int df[15];
bian now[100005];
void dfs(int st)
{
	if (st==k+1)
	{
		int kk=0,tpb=0;
		long long res=0;
		for (int i=1;i<=k;i++)
		{
			if (df[i])
			{
				kk++;
				res+=c[i];
				for (int j=1;j<=n;j++)
				{
					tpb++;
					now[tpb].u=kk+n;
					now[tpb].v=j;
					now[tpb].w=a[i][j];
				}
			}
		}
		sort(now+1,now+tpb+1,cmp);
		int cnt=0;
		for (int i=1;i<=n+kk;i++)
		{
			fa[i]=i;
		}
		int j1=1,j2=1;
		while (j1<=m&&j2<=tpb)
		{
			bian ymh;
			if (q[j1].w<=now[j2].w)
			{
				ymh=q[j1++];
			}
			else
			{
				ymh=now[j2++];
			}
			int u=ymh.u,v=ymh.v,w=ymh.w;
			if (find(u)!=find(v))
			{
				hb(u,v);
				res+=(long long)w;
				cnt++;
			}
			if (res>=ot)
			{
				return ;
			}
			if (cnt==n+kk-1)
			{
				break;
			}
		}
		while (j1<=m)
		{
			bian ymh=q[j1++];
			int u=ymh.u,v=ymh.v,w=ymh.w;
			if (find(u)!=find(v))
			{
				hb(u,v);
				res+=(long long)w;
				cnt++;
			}
			if (res>=ot)
			{
				return ;
			}
			if (cnt==n+kk-1)
			{
				break;
			}
		}
		while (j2<=tpb)
		{
			bian ymh=now[j2++];
			int u=ymh.u,v=ymh.v,w=ymh.w;
			if (find(u)!=find(v))
			{
				hb(u,v);
				res+=(long long)w;
				cnt++;
			}
			if (res>=ot)
			{
				return ;
			}
			if (cnt==n+kk-1)
			{
				break;
			}
		}
		
		ot=min(ot,res);
		return ;
	}
	df[st]=0;
	dfs(st+1);
	df[st]=1;
	dfs(st+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].w);
	}
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		if (c[i]!=0)
		{
			flaga=1;
		}
		int fl=0;
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if (a[i][j]==0)
			{
				fl=1;
				cp[i]=j;
			}
		}
		if (fl==0)
		{
			flaga=1;
		}
	}
	
	if (flaga==0)
	{
		for (int i=1;i<=k;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (j==cp[i])
				{
					continue;
				}
				q[++m].u=cp[i];
				q[m].v=j;
				q[m].w=a[i][j];
			}
		}
		sort(q+1,q+m+1,cmp);
		int cnt=0;
		long long ans=0;
		for (int i=1;i<=n;i++)
		{
			fa[i]=i;
		}
		for (int i=1;i<=m;i++)
		{
			int u=q[i].u,v=q[i].v,w=q[i].w;
			if (find(u)!=find(v))
			{
				hb(u,v);
				ans+=(long long)w;
				cnt++;
			}
			if (cnt==n-1)
			{
				break;
			}
		}
		printf("%lld",ans);
	}
	else
	{
		sort(q+1,q+m+1,cmp);
		dfs(1);
		printf("%lld",ot);
	}
	return 0;
}

