#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 10010
#define M 1000010
struct edge {
	int u, v, w;
	bool operator < (const edge &T) const {
		return w < T.w;
	}
} e[M << 2];
int n, m, k, fa[N], c[15], a[15][N];
ll ans;

int Find(int x) {
	return x == fa[x] ? x : (fa[x] = Find(fa[x]));
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
		
	}
	for (int i = 1; i <= n + 1; ++i) fa[i] = i;
	if (k == 0) {
		sort(e + 1, e + m + 1);
		int cnt = 1;
		for (int i = 1; i <= m; ++i) {
			int _u = Find(e[i].u), _v = Find(e[i].v);
			if (cnt == n) break;
//			cout << _u << " " << _v << "??\n";
			if (_u != _v) {
				ans += e[i].w;
				fa[_u] = _v;
				++cnt;
			}
//			cout << i << " " << ans << endl;
		}
		printf("%lld", ans);
		return 0;
	}
	bool fl = 1;
	for (int i = 1; i <= k; ++i) {
		scanf("%d", c + i);
		if (c[i]) fl = 0;
		for (int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
//		cout << c[i] << endl;
	}
	if (fl) {
	//	puts("??");
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				ll x = 1e18;
				for (int l = 1; l <= k; ++l) {
					x = min(x, 1ll * a[l][i] + 1ll * a[l][j]);
				}
				e[++m] = (edge) { i, j, x };
			}
		}
		for (int i = 1; i <= n + 1; ++i) fa[i] = i;
		sort(e + 1, e + m + 1);
		int cnt = 1;
		for (int i = 1; i <= m; ++i) {
			int _u = Find(e[i].u), _v = Find(e[i].v);
			if (cnt == n) break;
//			cout << _u << " " << _v << "??\n";
			if (_u != _v) {
				ans += e[i].w;
				fa[_u] = _v;
				++cnt;
			}
//			cout << i << " " << ans << endl;
		}
		printf("%lld", ans);
		return 0;
	}
	sort(e + 1, e + m + 1);
	int cnt = 1;
	for (int i = 1; i <= m; ++i) {
		int _u = Find(e[i].u), _v = Find(e[i].v);
		if (cnt == n) break;
//		cout << _u << " " << _v << "??\n";
		if (_u != _v) {
			ans += e[i].w;
			fa[_u] = _v;
			++cnt;
		}
//		cout << i << " " << ans << endl;
	}
	printf("%lld", ans);
	return 0;
}
/*
4 5 0
1 4 6
2 3 7
4 2 5
4 3 4
1 3 2
*/
