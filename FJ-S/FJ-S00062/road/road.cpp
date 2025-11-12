#include <iostream>
#include <algorithm>
using namespace std;

#define int long long
int parent[10005];
int find(int x)
{
	if(parent[x]==x)
	{
		return x;
	}
	return parent[x]=find(parent[x]);
}
int si[10005];
bool merge(int i,int j)
{
	int a=find(i);
	int b=find(j);
	if(a==b)
	{
		return false;
	}
	if(si[a]<si[b])
	{
		swap(a,b);
	}
	si[a]+=si[b];
	parent[b]=a;
	return true;
}
struct Edge
{
	int u;
	int v;
	int w;
	bool check;
}edge[1000005],temp[1000005];
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int n,m,k;
int kruskal()
{
	for(int i=1;i<=n+k;i++)
	{
		parent[i]=i;
		si[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		temp[i]=edge[i];
	}
	sort(temp+1,temp+m+1,cmp);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		if(merge(temp[i].u,temp[i].v))
		{
			ans+=temp[i].w;
			edge[i].check=true;
		}
	}
	return ans;
}
int c[15];
int d[15][10005];
int ans=1e18;
void dfs(int now,int sum)
{
	if(now>k)
	{
		ans=min(ans,sum+kruskal());
		return;
	}
	dfs(now+1,sum);
	for(int j=1;j<=n;j++)
	{
		m++;
		edge[m]={n+now,j,d[now][j]};
	}
	dfs(now+1,sum+c[now]);
	m-=n;
}
signed main()
{
	//64 pts
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	sort(edge+1,edge+m+1,cmp);
	int idx=kruskal();
	idx=0;
	for(int i=1;i<=m;i++)
	{
		if(edge[i].check)
		{
			idx++;
			edge[idx]=edge[i];
		}
	}
	m=idx;
	bool f=true;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i])
		{
			f=false;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>d[i][j];
			if(d[i][j])
			{
				f=false;
			}
		}
	}
	if(f)
	{
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
