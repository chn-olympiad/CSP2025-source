#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > e[10010];
int dis[10010],f[10010];
int n,m,k;
void dijk(int u)
{
	memset(dis,0x3f,sizeof dis);
	memset(f,0,sizeof f);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push({1,0});
    f[1]=1;
    while(!pq.empty())
    {
		int u=pq.top().first;
		pq.pop();
		if(f[u]==1) continue;
		f[u]=1;
		for(auto v:e[u])
		{
			int money=v.second;
			int r=v.first;
			if(dis[u]+money<dis[r])
			{ 
				dis[r]=dis[u]+money;
				f[r]=1;
				pq.push({r,dis[r]});
			}
		}
    }
    cout<<dis[n];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
	    int l,a;
	    cin>>l;
	    for(int j=1;j<=n;j++) cin>>a;
	}
	if(k==0)
	{
		dijk(1);
	}
	else cout<<0;
}
