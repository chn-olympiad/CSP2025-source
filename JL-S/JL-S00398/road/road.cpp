#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int c[13];
int a[13][10005];
int anss;
struct edge
{
	int to,val;
};
vector<edge>g[1000006];
bool vis[1000006];
int ans[1000006];
void dfs(int p,int fa)
{
	for(auto x:g[p])
	{
		
	}
}
#define ls p<<1
#define rs p<<1|1
struct node
{
	int lazy,sum;
}e[4000006];
void update(int l,int r,int x,int y,int val,int p)
{
	if(x<=l||y<=r)
	{
		e[p].sum=l-r+1;
		e[p].lazy=0;
		return;
	}
	int mid=(l+r)>>1;
	if(l<=mid)
	{
		update(1,n,l,mid,val,ls);
	}
	if(r>mid)
	{
		update(1,n,mid+1,r,val,rs);
	}
	e[p].sum=e[ls].sum+e[rs].sum;
}
int query(int l,int r,int x,int y,int p)
{
	if(x<=l||y<=r)
	{
		return e[p].sum;
	}
	int mid=(l+r)>>1;
	int ans=0;
	if(l<=mid)
	{
		ans+=query(1,n,l,mid,ls);
	}
	if(r>mid)
	{
		ans+=query(1,n,mid+1,r,rs);
	}
	return ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		anss+=w;
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n+1;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	printf("%lld\n",anss);
	return 0;
}