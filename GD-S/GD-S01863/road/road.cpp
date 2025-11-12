#include<bits/stdc++.h>
using namespace std;
#define int long long

int G[10001][10001];
int c[11];
int a[11][10001];
int d[10001];
int n, m, k;
int dis[10001];
bool vis[10001];

int f()
{
	int ans = 0;
	queue<int>q;
	
	q.push(1);
	dis[1] = 0;
	
	while (q.size())
	{
		auto u = q.front();
		q.pop();
		ans += dis[u];
		cerr << u << ' ' << dis[u] << '\n';
		for (int i = 1; i <= n + k; ++i)
		{
			pair<int, int> v = {i, G[u][i]};
			d[v.first]--;
			dis[v.first] = min(dis[v.first], dis[u] + v.second);
			if (d[v.first] <= 1 && !vis[v.first])
			{
				vis[v.first] = 1;
				q.push(v.first);
			}
		}
	}
	return ans;
}

int solveA()
{
	for (int i = 1; i <= k; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			G[n + i][j] = a[i][j];
		}
	}
	
	return f();
	
}

signed main()
{
	ifstream cin("road.in");
	ofstream cout("road.out");
	
	cin >> n >> m >> k;
	
	memset(G, 0x3f, sizeof(G));
	memset(dis, 0x3f, sizeof(dis));
	
	for (int i = 1; i <= m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		G[u][v] = w;
		G[v][u] = w;
		d[u]++, d[v]++;
	}
	bool flag = 0;
	for (int i = 1; i <= k; ++i)
	{
		cin >> c[i];
		flag |= c[i];
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
		}
	}
	if (!flag)
	{
		cout << solveA();
	}
	else
	{
		cout << 1;
	}
}
