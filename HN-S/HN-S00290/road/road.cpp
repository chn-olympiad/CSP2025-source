#include <bits/stdc++.h>
using namespace std;

int n , m , k;
int dis[10005] , vis[10005] , ans[10005];
struct node
{
	int v , w;
	bool operator < (const node &b)const
	{
		return b.w < w;
	}
};
vector<node>e[10005];
priority_queue<node>pq;

void dij(int s)
{
	for(int i = 1;i <= n;i ++)
	{
		dis[i] = 1e9;
		vis[i] = 0;
	}
	dis[s] = 0;
	pq.push({s , 0});
	while(pq.size())
	{
		node t = pq.top();
		int u = t.v;
		pq.pop();
		if(vis[u] == 1)
		{
			continue;
		}
		vis[u] = 1;
		for(int j = 0;j < e[u].size();j ++)
		{
			int v = e[u][j].v , w = e[u][j].w;
			if(dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
				if(vis[v] == 0)
				{
					pq.push({v , dis[v]});
				}
			}
		}
	}
	return ;
}

int main()
{
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin >> n >> m >> k;
	if(k == 0)
	{
		int sum = 0;
		for(int i = 1;i <= m;i ++)
		{
			int u , v , w;
			cin >> u >> v >> w;
			e[u].push_back({v , w});
			e[v].push_back({u , w});
		}
		for(int i = 1;i <= n;i ++)
		{
			dij(i);
			for(int j = 1;j <= n;j ++)
			{
				if(dis[j] == 0)
				{
					break;
				}
				if(ans[j] == 0)
				{
					ans[j] = dis[j];
				}
				else
				{
					ans[j] = min(dis[j] , ans[j]);					
				}
			}
		}
		for(int i = 1;i <= n;i ++)
		{
			sum += ans[i];
		}
		cout << sum;
		return 0;
	}
	return 0;
}
