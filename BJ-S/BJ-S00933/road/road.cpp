#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5;
int n,m,k,a[15][N],c[15],cnt,flag[N];
struct _
{
	int u,v,w;
}ed[N];
vector<pair<int,int> > edge[N];
priority_queue<pair<int,int> > q;
priority_queue<pair<int,pair<int,int> > > p;
int scs(int ans)
{
	for(int i=1;i<=n;++i) flag[i]=0;
	q.push({0,1});
	while(!q.empty())
	{
		int l=-q.top().first,x=q.top().second;q.pop();
		if(flag[x]) continue;
		flag[x]=1,ans+=l;
		for(int i=0;i<edge[x].size();++i)
		{
			int y=edge[x][i].first,z=edge[x][i].second;
			if(flag[y]) continue;
			q.push({-z,y});
		}
	}
	return ans;
}
int dfs(int i,int sum)
{
	if(i==k+1) return scs(sum);
	int ans=dfs(i+1,sum);
	for(int j=1;j<=n;++j)
	{
		edge[n+i].push_back({j,a[i][j]});
		edge[j].push_back({n+i,a[i][j]});
	}
	ans=min(ans,dfs(i+1,sum+c[i]));
	for(int j=1;j<=n;++j)
	{
		edge[n+i].pop_back();
		edge[j].pop_back();
	}
	return ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		int x,y,z;
		cin>>x>>y>>z;
		edge[x].push_back({y,z});
		edge[y].push_back({x,z});
	}
	p.push({0,{1,1}});
	while(!p.empty())
	{
		int l=-p.top().first,x=p.top().second.second,f=p.top().second.first;p.pop();
		if(flag[x]) continue;
		flag[x]=1,ed[++cnt]={f,x,l};
		for(int i=0;i<edge[x].size();++i)
		{
			int y=edge[x][i].first,z=edge[x][i].second;
			if(flag[y]) continue;
			p.push({-z,{x,y}});
		}
	}
	for(int i=1;i<=n;++i) edge[i].clear();
	for(int i=1;i<=cnt;++i)
	{
		int x=ed[i].u,y=ed[i].v,z=ed[i].w;
		if(x==y) continue;
		edge[x].push_back({y,z});
		edge[y].push_back({x,z});
	}
	bool book=1;
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		if(c[i]!=0) book=0;
		for(int j=1;j<=n;++j) cin>>a[i][j];
	}
	if(book)
	{
		for(int i=1;i<=k;++i)
		{
			for(int j=1;j<=n;++j)
			{
				edge[n+i].push_back({j,a[i][j]});
				edge[j].push_back({n+i,a[i][j]});
			}
		}
		cout<<scs(0)<<'\n';
		return 0;
	}
	cout<<dfs(1,0)<<'\n';
	return 0;
}