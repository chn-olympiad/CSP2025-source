#include<bits/stdc++.h>
#define int long long
using namespace std;

struct edge
{
	int nxt,num;
	bool operator < (const edge &X)const 
	{
		return num>X.num;
	}
};

void solve()
{
	int n,m,k,cnt=0,ans=0;
	cin>>n>>m>>k;
	vector<vector<edge> >vec(n+5);
	vector<bool>vis(n+5,0);
	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		cin>>v>>u>>w;
		vec[v].push_back({u,w});
		vec[u].push_back({v,w});
	}
	for(int i=1;i<=k;++i)
	{
		int x;
		cin>>x;
		for(int j=1;j<=n;++j)
		{
			int y;
			cin>>y;
		}
	}
	priority_queue<edge>qu;
	vis[1]=1;
	qu.push({1,0});
	while(qu.size()&&cnt<n)
	{
		int x=qu.top().nxt,y=qu.top().num;
		qu.pop();
		ans+=y;
		++cnt;
		for(auto z:vec[x])
		{
			if(vis[z.nxt])continue;
			vis[z.nxt]=1;
			qu.push({z.nxt,z.num});
		}
	}
	cout<<ans<<'\n';
	return ;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int t;t=1;
	while(t--)solve();
	return 0;
}
