#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

const int maxn = 3e6 + 10;

int n, m, k;
ll a[12][maxn], c[12];
ll ans;

struct edge {
	int u, v;
	ll w;
} ed[maxn], ed2[maxn];
int id[maxn], cnt, tot;

int fa[maxn];
int find(int x) { return (fa[x] == x ? x : fa[x] = find(fa[x])); }

void init() {
	ans = 0;
	for (int i = 1; i <= n; i++) fa[i] = i;
	cnt = 0;
}
void solve() {
	init();
	sort(ed + 1, ed + m + 1, [](const edge& x, const edge& y) {
		return x.w < y.w;
	});
	for (int i = 1; i <= m && cnt < n - 1; i++) {
		int fx = find(ed[i].u), fy = find(ed[i].v);
		if (fx != fy) {
			fa[fx] = fy, cnt++, ans += ed[i].w, id[cnt] = i;
		}
	}
	// cout << ans << "\n";
	for (int i = 0; i < (1 << k); i++) {
		ll res = 0;
		int add = 0;
		for (int j = 1; j <= k; j++)
			if ((i >> (j - 1)) & 1) {
				res += c[j], add++;
			}
		if (res > ans) continue;
		for (int i = 1; i < n; i++) ed2[i] = ed[id[i]];
		tot = n - 1;
		for (int j = 1; j <= k; j++)
			if ((i >> (j - 1)) & 1)
				for (int t = 1; t <= n; t++)
					ed2[++tot] = { n + j, t, a[j][t] };
		for (int j = 1; j <= n + k; j++) fa[j] = j;
		cnt = 0;
		sort(ed2 + 1, ed2 + tot + 1, [](const edge& x, const edge& y) {
			return x.w < y.w;
		});
		for (int j = 1; j <= tot && cnt < n + add - 1; j++) {
			int fx = find(ed2[j].u), fy = find(ed2[j].v);
			if (fx != fy) {
				fa[fx] = fy, cnt++, res += ed2[j].w;
				if (res >= ans) break; 
			}
		}
		ans = min(ans, res);
	}
	cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> n >> m >> k;	
	for (int i = 1; i <= m; i++)
		cin >> ed[i].u >> ed[i].v >> ed[i].w;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	solve();
	return 0;
}