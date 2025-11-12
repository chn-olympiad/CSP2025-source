#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c,a[10005],ans;
bool flag[10005];
struct edge
{
	int u,v,w;
};
bool cmp(edge a,edge b)
{
	return a.w > b.w;
}
vector <edge> e[1000005];
priority_queue <edge,vector <edge>,cmp> pq;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++)
	{
		cin >> u >> v >> w;
		e[u].push_back({u,v,w});
		e[v].push_back({v,u,w});
	}
	for (int z = 1;z <= k;z++)
	{
		cin >> c;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				e[i].push_back({i,j,c + a[i] + a[j]});
				e[j].push_back({j,i,c + a[i] + a[j]});
			}
		}
	}
	pq.push_back({0,1,0});
	flag[1] = 1;
	while(!pq.empty())
	{
		edge a = pq.top();
		pq.pop();
		u = a.u,v = a.v,w = a.w;
		if (flag[v])
		{
			continue;
		}
		flag[v] = 1;
		ans += w;
		for (int i = 0;i < e[v].size();i++)
		{
			pq.push(e[v][i]);
		}
	}
	cout << ans;
	return 0;
}
