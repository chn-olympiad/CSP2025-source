#include <bits/stdc++.h> 

namespace solve
{
	int n,m,k;
	long long ans=LONG_LONG_MAX;
	struct edge{int v;long long w;};
	std::vector<std::vector<edge>> G;
	std::vector<int> c;
	struct node
	{
		int id;
		long long dis; 
		friend operator<(const node& a,const node& b)
		{return a.dis>b.dis;}
	};
	std::priority_queue<node> q;
	std::vector<char> valid;
	std::vector<char> vis;
	std::vector<long long> dis;
	long long prim()
	{
		dis.assign(n+k+1,LONG_LONG_MAX>>1);
		vis.assign(n+k+1,false);
		q.push({1,0});
		dis[1]=0;
		long long ans=0;
		while(!q.empty())
		{
			node u=q.top();
			q.pop();
			if(vis[u.id]) continue;
			vis[u.id]=true;
			for(edge e:G[u.id])
				if((e.v<=n||valid[e.v-n])&&!vis[e.v]&&dis[e.v]>e.w)
				{
					dis[e.v]=e.w;
					q.push({e.v,e.w});
				}
		}
		for(int i=1;i<=n+k;i++)
			if(i<=n||valid[i-n])
				ans+=dis[i];
		return ans;
	}
	void dfs(int u=1,long long sum=0)
	{
		if(u>k)
		{
			ans=std::min(ans,sum+prim());
			return;
		}
		dfs(u+1,sum);
		valid[u]=true;
		dfs(u+1,c[u]+sum);
		valid[u]=false;
	}
	void main()
	{
		std::cin>>n>>m>>k;
		G.assign(n+k+1,{});
		c.assign(k+1,0);
		valid.assign(k+1,false);
		for(int i=0,u,v,w;i<m;i++)
		{
			std::cin>>u>>v>>w;
			G[u].push_back({v,w});
			G[v].push_back({u,w});
		}
		for(int u=n+1;u<=n+k;u++)
		{
			std::cin>>c[u-n];
			for(int v=1,w;v<=n;v++)
			{
				std::cin>>w;
				G[u].push_back({v,w});
				G[v].push_back({u,w});
			}
		}
		dfs();
		std::cout<<ans;
	}
}

int main()
{
#define PROBLEM_STLVECTOR "road"
#if 1
	freopen(PROBLEM_STLVECTOR".in","r",stdin);
	freopen(PROBLEM_STLVECTOR".out","w",stdout);
#endif
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve::main();
	return 0;
}
