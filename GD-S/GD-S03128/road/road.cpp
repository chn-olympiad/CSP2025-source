#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

using ll = long long;

const ll N = 1e5 + 5, M = 1e6 + 5, K = 15;

int n, m, k, f[N], idx[K][N];
ll c[N], ans;
bool vis[M << 1];
struct edge
{
	int u, v;
	ll w;
	bool f1, f2;
	const friend bool operator<(const edge &lhs, const edge &rhs) { return lhs.w > rhs.w; }
} e[M << 1];
priority_queue<edge> q;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void init() {}

namespace brute_force
{
	int cnt;
	ll sum, res;
	struct edge2
	{
		int u, v;
		ll w;
	} ed[M << 1];
	ll kruskal()
	{
		res = 0;
		for (int i = 1; i <= n + k; ++i)
			f[i] = i;
		sort(ed + 1, ed + cnt + 1, [](edge2 x, edge2 y)
			{ return x.w < y.w; });
		for (int i = 1, ru, rv; i <= cnt; ++i)
		{;
			if ((ru = find(ed[i].u)) == (rv = find(ed[i].v)))
				continue;
			f[ru] = rv;
			res += ed[i].w;
		}
		return res;
	}
	void solve1()
	{
		ans = LLONG_MAX;
		for (int s = 0; s < 1 << k; ++s)
		{
			cnt = sum = 0;
			for (int i = 1; i <= m; ++i)
			{
				if (!e[i].f1)
					ed[++cnt] = {e[i].u, e[i].v, e[i].w};
			}
			for (int i = 1; i <= k; ++i)
			{
				if (s >> i - 1 & 1) {
					sum += c[i];
					for (int x = 1; x <= n; ++x)
					{
						for (int y = 1; y <= n; ++y)
						{
							if (x == y)
								continue;
							ed[++cnt] = {x, y, e[idx[i][x]].w + e[idx[i][y]].w - (c[i] << 1)};
						}
					}
				}
			}
			ans = min(ans, kruskal() + sum);
		}
		cout << ans << endl;
	}
}

void solve()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n + k; ++i)
		f[i] = i;
	for (int i = 1; i <= m; ++i)
		cin >> e[i].u >> e[i].v >> e[i].w;
	for (int i = 1; i <= k; ++i)
	{
		ll w;
		cin >> c[i];
		for (int j = 1; j <= n; ++j)
		{
			cin >> w;
			e[++m] = {i + n, j, w + c[i], 1};
			idx[i][j] = m;
		}
	}
	if (k <= 5 && m <= 1e5)
		return brute_force::solve1();
	for (int i = 1; i <= m; ++i)
		q.push(e[i]);
	for (int u, v, ru, rv; q.size();)
	{
		auto cur = q.top();
		q.pop();
		if ((ru = find(u = cur.u)) == (rv = find(v = cur.v)))
			continue;
		if (cur.f1)
		{
			// cerr << "! " << u << ' ' << v << ' ' << vis[idx[u][v]] << endl;
			if (vis[idx[u - n][v]])
				continue;
			if (!cur.f2)
			{
				for (int i = 1, id; i <= n; ++i)
				{
					id = idx[u - n][i];
					q.push({u, i, e[id].w - c[u - n], 1, 1});
					// cerr << "+ " << u << ' ' << i << ' ' << e[id].w - c[u - n] << endl;
				}
			}
			vis[idx[u - n][v]] = 1;
		}
		ans += cur.w;
		f[ru] = rv;
		// cerr << ": " << u << ' ' << v << ' ' << cur.w << endl;
	}
	for (int i = 1, t1, t2; i <= k; ++i)
	{
		t1 = t2 = 0;
		for (int j = 1; j <= n; ++j)
		{
			if (vis[idx[i][j]])
			{
				if (t1)
					t2 = idx[i][j];
				else
					t1 = idx[i][j];
			}
		}
		if (!t1)
			continue;
		if (!t2)
			ans -= e[t1].w;
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int _ = 1;
	// cin >> _;
	init();
	while (_--)
		solve();
	return 0;
}
/*
g++ road.cpp -std=c++14 -O2 -Wall -o road.exe
*/
/*
我写了一个半小时然后发现萎了
我真的要喷人了
*/