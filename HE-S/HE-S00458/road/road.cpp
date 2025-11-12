#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
ll ans = LLONG_MAX;
int f[200010], a[15][10010], c[15];

struct node
{
	ll u, v, w;
};
vector<node> e;

int find(int x)
{
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

void join(int x, int y)
{
	f[find(x)] = find(y);
}

bool cmp(node xx, node yy)
{
	return xx.w < yy.w;
}

int solve(ll add)
{
	sort(e.begin(), e.end(), cmp);
	for (int i = 1; i <= n + k; i++) f[i] = i;
	ll cnt = 0, res = 0;
	for (int i = 0; i < m + add * n; i++)
	{
		ll u = e[i].u, v = e[i].v, w = e[i].w;
		if (find(u) == find(v)) continue;
		join(u, v);
		res += w;
		cnt++;
		if (cnt == n + add - 1) break;
	}
	return res;
}

void dfs(int step, int sum, int cnt)
{
	if (step > k)
	{
		ll tot = sum + solve(cnt);
		ans = min(ans, tot);
		return;
	}
	dfs(step + 1, sum, cnt);
	vector<node> e0 = e;
	for (int i = 1; i <= n; i++)
		e.push_back({n + step, i, a[step][i]});
	dfs(step + 1, sum + c[step], cnt + 1);
	e = e0;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	dfs(1, 0, 0);
	cout << ans << endl;
	return 0;
}
