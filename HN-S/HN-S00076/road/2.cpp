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
int n, m, k, fa[N], top, c[N], ok[N], cnt, ps[12];
pii a[12][N];
struct edge {
	int u, v, w;
}ed[M];
int find(int k)
{
	return fa[k] == k ? k : fa[k] = find(fa[k]);
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
	for (int i = 1; i <= m; ++i) {
		int fx = find(ed[i].u), fy = find(ed[i].v);
		if (fx != fy) {
			fa[fx] = fy;
			ok[++cnt] = i;
		}
	}
	ll ans = LLONG_MAX;
	for (int S = 0; S < 1 << k; ++S) {
	// for (int S : {1}) {
		ll sum = 0;
		for (int i = 0; i < k; ++i) {
			if ((S >> i) & 1) {
				sum += c[i];
			}
		}
		for (int i = 1; i <= n + k; ++i) {
			fa[i] = i;
		}
		for (int i = 0; i < k; ++i) {
			ps[i] = 1;
		}
		// cerr << sum << '\n';
		for (int i = 1; i <= cnt; ++i) {
			for (int j = 0; j < k; ++j) {
				if ((S >> j) & 1) {
					// cerr << j << ' ' << ps[j] << '\n';
					// cerr << a[j][ps[j]].first << '\n';
					while (ps[j] <= n && a[j][ps[j]].first < ed[ok[i]].w) {
						int fx = find(n + j + 1), fy = find(a[j][ps[j]].second);
						// cerr << n + j + 1 << ' ' << a[j][ps[j]].second << ' ' << a[j][ps[j]].first << '\n';
						if (fx != fy) {
							fa[fx] = fy;
							sum += a[j][ps[j]].first;
						}
						++ps[j];
					}
				}
			}
			int fx = find(ed[ok[i]].u), fy = find(ed[ok[i]].v);
			// cerr << ed[ok[i]].u << ' ' << ed[ok[i]].v << ' ' << ed[ok[i]].w << '\n';
			// cerr << '\n';
			if (fx != fy) {
				fa[fx] = fy;
				sum += ed[ok[i]].w;
			}
			// cerr << sum << '\n';
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}