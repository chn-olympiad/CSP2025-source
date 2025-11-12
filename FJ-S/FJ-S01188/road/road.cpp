# include <bits/stdc++.h>
# define int long long
using namespace std;
const int N = 1e4 + 10;
int n, m, k;
vector < pair < int, pair < int, int > > > edge;
int ans = 1e18, res;
int c[15];
int a[15][N];
struct node{
	int fa[N];
	void init() { for (int i = 1; i <= n + k; i ++) fa[i] = i; }
	int Find(int x) { return (fa[x] == x ? x : fa[x] = Find(fa[x])); }
} f;
void solve()
{
	f.init();
	vector < pair < int, pair < int, int > > > e = edge;
	sort(e.begin(), e.end());
	for (auto t : e)
	{
		int w = t.first, u = t.second.first, v = t.second.second;
		u = f.Find(u), v = f.Find(v);
		if (u == v) continue;
		f.fa[u] = v;
		res += w;
	}
}
void dfs(int i, int sum)
{
	if (i > k)
	{
		res = sum;
		solve();
		ans = min(ans, res);
		return ;
	}
	for (int j = 1; j <= n; j ++)
	{
		edge.push_back({a[i][j], {j, i + n}});
	}
	dfs(i + 1, sum + c[i]);
	for (int j = 1; j <= n; j ++) edge.pop_back();
	dfs(i + 1, sum);
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i ++)
	{
		cin >> u >> v >> w;
		edge.push_back({w, {u, v}});
	}
	int cnt = 0;
	f.init();
	vector < pair < int, pair < int, int > > > e = edge;
	edge.clear();
	sort(e.begin(), e.end());
	for (auto t : e)
	{
		int w = t.first, u = t.second.first, v = t.second.second;
		u = f.Find(u), v = f.Find(v);
		if (u == v) continue;
		f.fa[u] = v;
		res += w;
		cnt ++;
		edge.push_back({w, {u, v}});
		if (cnt == n - 1) break;
	}
	for (int i = 1; i <= k; i ++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j ++)
		{
			cin >> a[i][j];	
		} 
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}

