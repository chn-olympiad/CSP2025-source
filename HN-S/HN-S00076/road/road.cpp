#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
bool be;
constexpr int N = 1e4 + 15, M = 1e6 + 5;
int n, m, k, fa[N], top, c[N];
pii a[12][N];
ll ans;
struct edge {
	int u, v, w;
}ed[M];
int find(int k)
{
	return fa[k] == k ? k : fa[k] = find(fa[k]);
}
void dfs(int S, ll sum, vector<edge>E)
{
	int id = 0;
	for (int j = 0; j < k; ++j) {
		if ((S >> j) & 1) {
			id = j + 1;
		}
	}
	for (int j = id; j < k; ++j) {
		if (!((S >> j) & 1)) {
			vector<edge>e;
			for (int i = 1; i <= n + k; ++i) {
				fa[i] = i;
			}
			ll s = 0;
			int ps = 1;
			for (auto [u, v, w] : E) {
				while (ps <= n && a[j][ps].first < w) {
					int fx = find(n + j + 1), fy = find(a[j][ps].second);
					if (fx != fy) {
						fa[fx] = fy;
						s += a[j][ps].first;
						e.push_back({n + j + 1, a[j][ps].second, a[j][ps].first});
					}
					++ps;
				}
				int fx = find(u), fy = find(v);
				if (fx != fy) {
					fa[fx] = fy;
					s += w;
					e.push_back({u, v, w});
				}
			}
			ans = min(ans, s + sum + c[j]);
			dfs(S | (1 << j), sum + c[j], e);
		}
	}
}
bool en;
int main()
{
	freopen("road.in", "r", stdin);
#ifdef xu
	cerr << (&be - &en) / 1024.0 / 1024 << " MB\n------------------" << endl;
#else
	freopen("road.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> ed[i].u >> ed[i].v >> ed[i].w;
	}
	for (int i = 0; i < k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j].first;
			a[i][j].second = j;
		}
		sort(a[i] + 1, a[i] + 1 + n);
	}
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}
	sort(ed + 1, ed + 1 + m, [](edge a, edge b) {
		return a.w < b.w;
	});
	vector<edge>E;
	for (int i = 1; i <= m; ++i) {
		int fx = find(ed[i].u), fy = find(ed[i].v);
		if (fx != fy) {
			fa[fx] = fy;
			E.emplace_back(ed[i]);
			ans += ed[i].w;
		}
	}
	dfs(0, 0, E);
	cout << ans << endl;
	return 0;
}