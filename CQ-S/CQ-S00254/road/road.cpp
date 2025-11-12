#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int x,y,w;
	bool operator < (edge b)
	{
		return w<b.w;
	}
};
vector<edge>eg;
int n,m,k;
int a[15];
bool v[15];
int f[11005];
int find(int x)
{
	return (f[x]==x?x:f[x]=find(f[x]));
}
bool merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)
	{
		return false;
	}
	f[fy]=fx;
	return true;
}
long long ans=2e18;
long long kruskal()
{
	for(int i=1;i<=n+k;i++)
	{
		f[i]=i;
	}
	long long ans=0;
	for(auto i:eg)
	{
		if(i.x>n&&!v[i.x-n])
		{
			continue;
		}
		if(merge(i.x,i.y))
		{
			ans+=i.w;
		}
	}
	return ans;
}
void dfs(int id,long long sum)
{
	if(sum>=ans)
	{
		return ;
	}
	if(id>k)
	{
		/*for(int i=1;i<=k;i++)
		{
			cout<<v[i]<<" ";
		}
		cout<<"\n";*/
		ans=min(ans,sum+kruskal());
		return ;
	}
	v[id]=1; 
	dfs(id+1,sum+a[id]);
	v[id]=0;
	dfs(id+1,sum);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		eg.push_back({x,y,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
		int x;
		for(int j=1;j<=n;j++)
		{
			cin>>x;
			eg.push_back({n+i,j,x});
		}
	}
	sort(eg.begin(),eg.end());
	dfs(1,0);
	cout<<ans;
	return 0;
}
//40~80pts
