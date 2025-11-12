#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 100;
const int M = 1e6 + 100;
int n, m, k;
struct node
{
	int v, w;
};
vector<node> mp[N];
int a[15][N];
bool p[N];
int ans = 1e18;
void dfs(int tot, int val)
{
	if (tot == n)
	{
		ans = min(ans, val);
		return;
	}
	int minn = 0;
	for (int i = 0; i < mp[tot].size(); i++)
	{
		if (!p[mp[tot][i].v]) minn = min(minn, mp[tot][i].w);
	}
	for (int i = 0; i < mp[tot].size(); i++)
	{
		if (!p[mp[tot][i].v] && mp[tot][i].w == minn)
		{
			p[mp[tot][i].v] = true;
			dfs(mp[tot][i].v, val + mp[tot][i].w);
			p[mp[tot][i].v] = false;
		}
	}
	return;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	int u, v, w;
	for (int i = 1; i <= m; i++)
	{
		scanf("%lld%lld%lld", &u, &v, &w);
		mp[u].push_back({v, w});
		mp[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%lld", &a[i][0]);
		for (int j = 1; j <= n; j++)
		{
			scanf("%lld", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		p[i] = true;
		dfs(i, 0);
		p[i] = false;
	}
	printf("%lld", ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
