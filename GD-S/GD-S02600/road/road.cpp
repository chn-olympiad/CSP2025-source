#include<bits/stdc++.h>
using namespace std;
int n,m,k,dis[10010],a,s[12];
long long ans=0;
struct pos
{
	int to,w;
	bool operator<(const pos &h)const
	{
		return h.w<w;
	}
};
vector<pos>g[1000010];
priority_queue<pos>q;
bool vis[1000010],flag[12];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>z;
		g[x].push_back({y,z});
		g[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>s[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a;
			g[i+n].push_back({j,s[i]+a});
			g[j].push_back({i+n,a});
		}
	}
	for(int i=1;i<=n+k;i++)dis[i]=2e9;
	dis[1]=0;
	q.push({1,0});
	while(!q.empty())
	{
		pos v=q.top();
		q.pop();
		if(vis[v.to])continue;
		vis[v.to]=1;
		for(pos i:g[v.to])
		{
			if(i.to>n)
			{
				if(flag[i.to-n])i.w-=s[i.to-n];
			}
			if(dis[i.to]>dis[v.to]+i.w)
			{
				dis[i.to]=dis[v.to]+i.w;
				if(i.to>n)flag[i.to-n]=1;
			}
			if(!vis[i.to])
			q.push({i.to,dis[i.to]});
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans+=dis[i];
		cout<<dis[i]<<endl;
	}
	cout<<ans;
	return 0;
}
