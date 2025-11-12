#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10, M = 1e7 + 10;
int n, m, k, fa[N], tot, val[N], c[15], mp[N][N];
struct node {
	int u, v, w, t;
} s[M];
int find (int x) {
	if (x == fa[x]) return x;
	return fa[x] = find (fa[x]);
}
bool cmp (node a, node b) {
	return a.w < b.w;
}
signed main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	scanf ("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= n; i ++) fa[i] = i;
	for (int i = 1, x, y, z; i <= m; i ++) {
		scanf ("%lld%lld%lld", &x, &y, &z);
		s[++ tot].u = x, s[tot].v = y, s[tot].w = z;
	}	
	sort (s + 1, s + 1 + tot, cmp);
	int ans = 0;
	for (int i = 1, x, y; i <= tot; i ++) {
		x = find (s[i].u), y = find (s[i].v);
		if (x != y) {
			fa[y] = x;
			ans += s[i].w;
			mp[s[i].u][s[i].v] = mp[s[i].v][s[i].u] = s[i].w;
		}
	}
//	cout << ans << endl;
	for (int T = 1; T <= k; T ++) {
		cin >> c[T];
		int sum = c[T] + ans;
		for (int i = 1; i <= n; i ++) cin >> val[i];
		for (int i = 1; i <= n; i ++) {
			for (int j = i + 1; j <= n; j ++) {
				if (mp[i][j] != 0 && mp[i][j] > val[i] + val[j]) {
					cout << mp[i][j] << ' ';
					sum = sum - mp[i][j] + val[i] + val[j];
				}
			}
		}
//		cout << sum << endl;
		ans = min (ans, sum);
	}
	cout << ans << endl;
//	for (int i = 1; i <= k; i ++) {
//		if (us[i] > 1) {
//			ans -= (us[i] - 1) * c[i];
//		}
//	}
//	cout << ans << endl;
}
