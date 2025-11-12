#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=1e8+10,K=20;
int b[K][N],flag[N],fa[N],n,m,k,ans,cnt,sum;
struct Node
{
	int u,v,w;
}a[N];
bool cmp(Node x,Node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if (fa[x]==x)
	{
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
void add(int u,int v)
{
	fa[u]=find(fa[v]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1; i<=m; i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[++cnt]={x,y,z};
	}
	for (int i=1; i<=n; i++)
	{
		fa[i]=i;
	}
	for (int i=1; i<=k; i++)
	{
		int w;
		scanf("%d",&w);
		for (int j=1; j<=n; j++)
		{
			int x;
			scanf("%d",&x);
			b[i][j]=x;
		}
		for (int j=1; j<=n; j++)
		{
			for (int o=j+1; o<=n; o++)
			{
				a[++cnt]={j,o,b[i][j]+b[i][o]+w};
			}
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for (int i=1; i<=cnt; i++)
	{
		if (find(a[i].u)!=find(a[i].v))
		{
			ans+=a[i].w;
			if (flag[a[i].u]==0)
			{
				sum++;
				flag[a[i].u]=1;
			}
			if (flag[a[i].v]==0)
			{
				sum++;
				flag[a[i].v]=1;
			}
			add(a[i].u,a[i].v);
			if (sum==n)
			{
				printf("%d\n",ans);
				return 0;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
