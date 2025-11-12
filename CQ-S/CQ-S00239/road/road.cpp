#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10100, K = 15, M = 1000010;
int n, m, k, fa[N], c[K], len[K];
int ans = 1e18, res;
struct P {
	int x, y, z;
	bool operator < (const P &t) const { return z < t.z; }
}s[M], ss[K][N], S[M], la[K][N];
inline int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
void work(int ad) {
	for (int i = 1; i <= n + k; i ++ ) fa[i] = i;
	res = 0;
	int nm = 0;
	for (int i = 1; i <= m; i ++ ) {
		int x = get(s[i].x), y = get(s[i].y);
		if (x != y) {
			fa[x] = y;
			res += s[i].z;
			S[++nm] = s[i];
		}
	}
	ans = min(ans, res + ad);
	m = nm;
	for (int i = 1; i <= m; i ++ ) s[i] = S[i];
}
void merge(int u) {
	int nm = 0;
	int l = 1, r = 1;
	while (l <= m || r <= n) {
		if (r > n || l <= m && s[l].z < ss[u][r].z) S[++nm] = s[l ++ ];
		else S[++nm] = ss[u][r ++ ];
	}
	m = nm;
	for (int i = 1; i <= m; i ++ ) s[i] = S[i];
}
void dfs(int u, int ad) {
	if (u == k + 1) return;
	dfs(u + 1, ad);
	len[u] = m;
	for (int i = 1; i <= m; i ++ ) la[u][i] = s[i];
	merge(u);
	work(ad + c[u]);
	dfs(u + 1, ad + c[u]);
	m = len[u];
	for (int i = 1; i <= m; i ++ ) s[i] = la[u][i];
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++ ) cin >> s[i].x >> s[i].y >> s[i].z;
	for (int i = 1; i <= k; i ++ ) {
		cin >> c[i];
		for (int j = 1; j <= n; j ++ ) cin >> ss[i][j].z, ss[i][j].x = i + n, ss[i][j].y = j;
		sort(ss[i] + 1, ss[i] + n + 1);
	}
	sort(s + 1, s + m + 1);
	work(0);
	dfs(1, 0);
	cout << ans;
	return 0;
}
