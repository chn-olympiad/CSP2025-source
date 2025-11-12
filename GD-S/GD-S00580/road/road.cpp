#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+5;
int n,m,k,c[15],tmp,ans=0,vis[15];
struct edge
{
	int v,w;
};
struct node
{
	int val,id;
}a[10005];
vector<edge> e[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		e[x].push_back((edge){y,z});
		e[y].push_back((edge){x,z});
	}
	for(int i=1;i<=n;i++)
	{
		a[i].val=inf;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&tmp);
			if(a[j].val>tmp)
			{
				a[j].val=tmp;
				a[j].id=i;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		int mn=1e9+7;
		for(int j=0;j<e[i].size();j++)
		{
			if(mn>e[i][j].w)
			{
				mn=e[i][j].w;
			}
		}
		if(vis[a[i].id]==0&&mn>a[i].val+c[a[i].id])
		{
			ans=ans+(a[i].val+c[a[i].id]);
			vis[a[i].id]=1;
		}
		else
		{
			if(vis[a[i].id]==1)
			{
				if(mn<a[i].val)
				{
					ans+=mn;
				}
				else
				{
					ans+=a[i].val;
				}
			}
			else
			{
				ans+=mn;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
