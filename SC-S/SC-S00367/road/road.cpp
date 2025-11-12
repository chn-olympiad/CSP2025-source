#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot,head[1000005],vis[1000005];
struct sd{
	int next_,to,val;
}edge[1000005];
int dfs(int point)
{
	vis[point]=1;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0) break;
		if(i==n) return 0;
	}
	int res=1<<30;
	for(int i=head[point];i;i=edge[i].next_)
	{
		if(vis[edge[i].to]) break;
		res=min(res,dfs(edge[i].to)+edge[i].val);
	}
	return res;
}
void add(int x,int y,int z)
{
	edge[++tot].to=y;
	edge[tot].next_=head[x];
	edge[tot].val=z;
	head[x]=tot;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	for(int i=1;i<=k;i++)
	{
		int c;
		scanf("%d",&c);
		for(int j=1;j<=n;j++)
		{
			int a;
			scanf("%d",&a);
			add(k+n,a,c);
			add(a,k+n,c);
		}
	}
	int mn=1<<30;
	for(int i=1;i<=n;i++)
	{
		mn=min(mn,dfs(i));
		for(int j=1;j<=n+k;j++)
		{
			vis[j]=0;
		}
	}
	printf("%d",mn);
	return 0;
}