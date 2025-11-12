#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int K = 10 + 1;
const int N = 1e4 + 1;
int n, m, k, c[K], fa[N], cost[K][N];
struct node
{
	int u, v, w;
};
vector<node> g;
int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
bool cmp(node x, node y)
{
	return x.w < y.w;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g.push_back({u, v, w});
	}
	bool flag = 1;
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		if(c[i]) flag = 0;
		bool flag1 = 0;
		for(int j = 1; j <= n; j++)
		{
			cin >> cost[i][j];
			if(!cost[i][j]) flag1 = 1;
		}
		flag &= flag1;
	}
	if(flag)
	{
		for(int i = 1; i <= k; i++)
		{
			int x = 0;
			for(int j = 1; j <= n; j++)
			{
				if(!cost[i][j])
				{
					x = j;
					break;
				}
			}
			for(int j = 1; j <= n; j++)
			{
				g.push_back({x, j, cost[i][j]});
			}
		}
	}
	sort(g.begin(), g.end(), cmp);
	ll sum = 0;
	int l = g.size();
	for(int i = 0; i < l; i++)
	{
		int x = find(g[i].u), y = find(g[i].v);
		if(x != y)
		{
			fa[x] = y;
			sum += g[i].w;
		}
	}
	cout << sum;
	return 0;
}

