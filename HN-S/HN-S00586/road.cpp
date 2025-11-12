#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void FileIO (string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int N = 1e6 + 10;

struct Edge {
	int x, y, z;
} ed[N], e[N];

int n, m, k, ecnt, fa[N], sum[N], cst[15];
ll ans, now;

void Clear () {
	for (int i = 1; i <= n + k; i++) fa[i] = 0, sum[i] = 1;
}

int Find (int x) {
	return (fa[x] ? fa[x] = Find(fa[x]) : x);
}

bool Merge (int x, int y) {
	x = Find(x), y = Find(y);
	if (x == y) return 0;
	if (sum[x] < sum[y]) swap(x, y);
	fa[y] = x, sum[x] += sum[y];
	return 1;
}

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	FileIO("road");
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> ed[i].x >> ed[i].y >> ed[i].z;
	for (int i = 0; i < k; i++) {
		cin >> cst[i];
		for (int j = 1, x; j <= n; j++) cin >> x, e[++ecnt] = {n + i + 1, j, x};
	}
	sort(ed + 1, ed + m + 1, [](const Edge &i, const Edge &j){return i.z < j.z;});
	for (int i = 1; i <= m; i++)
			if (Merge(ed[i].x, ed[i].y))
				ans += ed[i].z, e[++ecnt] = ed[i];
	// cout << ans << '\n';
	sort(e + 1, e + ecnt + 1, [](const Edge &i, const Edge &j){return i.z < j.z;});
	for (int i = 1; i < (1 << k); i++) {
		now = 0, Clear();
		for (int j = 0; j < k; j++) now += (i >> j & 1) * cst[j];
		for (int j = 1; j <= ecnt; j++) {
			if (e[j].x > n && ((i >> (e[j].x - n - 1)) & 1) == 0) continue;
			now += Merge(e[j].x, e[j].y) * e[j].z;
		}
		ans = min(ans, now);
		// cout << i << ' ' << now << '\n';
	}
	cout << ans;
	return 0;
}
