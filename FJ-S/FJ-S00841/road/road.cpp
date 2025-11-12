#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4 + 5, M = 2e6 + 5;
int n, m, k, cnt, ans, fa[N];
int c[15], x[15][N];
struct T { int u, v, w; } t[M], a[M];
bool cmp(T x, T y) { return x.w < y.w; }
int find(int x) { return (x == fa[x] ? x : fa[x] = find(fa[x])); }
int work(int p) {
	for (int i = 1; i <= p; i++) fa[i] = i;
	sort(t + 1, t + m + 1, cmp); cnt = ans = 0;
	for (int i = 1; i <= m; i++) {
		int x = t[i].u, y = t[i].v;
		x = find(x), y = find(y);
		if(x == y) continue;
		fa[x] = y, ans += t[i].w;
		if((++ cnt) == p - 1) break; 
	} return ans;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> t[i].u >> t[i].v >> t[i].w;
		a[i] = t[i];
	} bool ok = 1;
	for (int i = 1; i <= k; i++) {
		cin >> c[i]; bool flag = 0;
		for (int j = 1; j <= n; j++) cin >> x[i][j], flag |= (x[i][j] == 0);
		if(flag) {
			for (int j = 1; j <= n; j++) {
				if(!x[i][j]) {
					for (int k = 1; k <= n; k++) {
						if(k != j) t[++ m] = {j, k, x[i][k]};
					}
					break;
				} 
			}
		}
		else ok = 0;
	}
	if(ok || k == 0) cout << work(n) << '\n';
	else {
		int mm = m;
		int mi = 1e18;
		for (int i = 0; i < (1 << k); i++) {
			int cnt = 0, sum = 0;
			m = mm;
			for (int i = 1; i <= m; i++) t[i] = a[i];
			for (int j = 1; j <= k; j++) {
				if(i & (1 << (j - 1))) {
					cnt ++; sum += c[j]; 
					if(sum > mi) break;
					for (int o = 1; o <= n; o++) t[++ m] = {o, n + j, x[j][o]};
				}
			}
			if(sum > mi) continue;
			mi = min(mi, work(n + cnt) + sum);
		} cout << mi;
	}
	return 0;
}
