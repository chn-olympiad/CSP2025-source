#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define pii pair<int,int>
#define mkp(x,y) make_pair(x,y)
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
#define filename "road"
struct DSU
{
	int fa[10020];
	DSU()
	{
		for (int i = 1; i <= 10010; i++)fa[i] = i;
	}
	int find(int x)
	{
		if (fa[x] == x)return x;
		return fa[x] = find(fa[x]);
	}
	void u(int x, int y)
	{
		fa[find(x)] = find(y);
	}
};
vector<pair<pii, int>>solve_key_edge(int n, vector<pair<pii, int>>&edge)
{
	vector<pair<pii, int>>ret;
	ret.reserve(n);
	sort(edge.begin(), edge.end(), [](pair<pii, int>x, pair<pii, int>y)
	{
		return x.second < y.second;
	});
	DSU dsu;
	int cnt = n;
	for (auto &x : edge)
	{
		if (dsu.find(x.first.first) != dsu.find(x.first.second))
		{
			dsu.u(x.first.first, x.first.second);
			ret.push_back(x);
			cnt--;
		}
		if (cnt == 1)break;
	}
	return ret;
}

ll _cnt = 0;

ll solve_k(int n, vector<pair<pii, int>>edge, const vector<vector<pair<pii, int>>>&ae, int k, int bt)
{
	edge.reserve(n + __builtin_popcount(bt)*n);
	for (int i = 1; i <= k; i++)
	{
		if ((bt >> i) & 1)
		{
			int x = edge.size();
			for (auto x : ae[i])edge.push_back(x);
			inplace_merge(edge.begin(), edge.begin() + x, edge.end(), [](pair<pii, int>x, pair<pii, int>y)
			{
				return x.second < y.second;
			});
		}
	}
	int cnt = n + __builtin_popcount(bt);
	_cnt += edge.size();
	ll res = 0;
	DSU dsu;
	for (auto &x : edge)
	{
		if (dsu.find(x.first.first) != dsu.find(x.first.second))
		{
			dsu.u(x.first.first, x.first.second);
			res += x.second;
			cnt--;
		}
		if (cnt == 1)break;
	}
	return res;
}

void work()
{
	int n, m, k;
	cin >> n >> m >> k;
//	cerr<<clock()<<endl;
	vector<pair<pii, int>>edge;
	edge.reserve(m);
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		edge.push_back({{x, y}, z});
	}
	vector<int>c(k + 1);
	vector<vector<int>>a(k + 1, vector<int>(n + 1));
	vector<vector<pair<pii, int>>>ae(k + 1);
	for (int i = 1; i <= k; i++)
	{
		cin >> c[i];
		ae[i].reserve(n);
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			ae[i].push_back({{j, n + i}, a[i][j]});
		}
		sort(ae[i].begin(), ae[i].end(), [](pair<pii, int>x, pair<pii, int>y)
		{
			return x.second < y.second;
		});
	}
//	cerr<<clock()<<endl;
	auto keyedge = solve_key_edge(n, edge);
	ll ans = 0x3f3f3f3f3f3f3f3f;
	for (int bt = 0; bt < (1 << k); bt++)
	{
		ll res = 0;
		for (int i = 0; i < k; i++)if ((bt >> i) & 1)res += c[i + 1];
		ans = min(ans, res + solve_k(n, keyedge, ae, k, bt << 1));
	}
	cout << ans << endl;
//	cerr << _cnt << endl;
}
signed main()
{
#ifndef LOCAL
#ifdef filename
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int t;
//	cin >> t;
	t = 1;
	while (t--)
	{
		work();
	}
	return 0;
}