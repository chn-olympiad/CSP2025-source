#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int x,y,z;
};
int n,m,k,minn=1e18;
node g[2000005];
node v[2000005];
int fa[200005];
int a[15];
int b[15][200005];
int c[15];
bool cmp(node a,node b)
{
	return a.z<b.z;
}
int find(int x)
{
	if (fa[x]==0)
		return x;
	return fa[x]=find(fa[x]);
}
int kruscar()
{
	for (int i=1;i<=n+k;i++)
		fa[i]=0;
	int t=0,ans=0;
	for (int i=1;i<=m;i++)
	{
		t++;
		v[t].x=g[t].x;
		v[t].y=g[t].y;
		v[t].z=g[t].z;
	}
	int sum=0;
	for (int i=1;i<=k;i++)
	{
		if (c[i]==1)
		{
			ans+=a[i]; 
			for (int j=1;j<=n;j++)
			{
				sum++;
				t++;
				v[t].x=i+n;
				v[t].y=j;
				v[t].z=b[i][j];
			}
		}
	}
	sort(v+1,v+t+1,cmp);
	int k=0;
	for (int i=1;i<=t;i++)
	{
		if (k==n+sum-1)
			break;
		int fx=find(v[i].x);
		int fy=find(v[i].y);
		if (fx!=fy)
		{
			k++;
			ans+=v[i].z;
			fa[fx]=fy;
		}
	}
	return ans;
}
void dfs(int x)
{
	if (x==k+1)
	{
		minn=min(minn,kruscar());
		return;
	}
	c[x]=1;
	dfs(x+1);
	c[x]=0;
	dfs(x+1); 
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		g[i].x=x;
		g[i].y=y;
		g[i].z=z;
	}
	for (int i=1;i<=k;i++)
	{
		cin>>a[i];
		for (int j=1;j<=n;j++)
			cin>>b[i][j];
	}
	dfs(1);
	cout<<minn;
	return 0;
}

