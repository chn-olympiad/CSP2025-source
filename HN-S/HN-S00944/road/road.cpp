#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 1e5 + 5, M = 2e4 + 5;
int n, m, K, fu[M], op[15], h[M][15];
//struct edge {
//	int dian, lu;
//};
//vector<edge> v[15][M];
struct node {
	int u, v, w; 
} a[N], b[15][M];
int tot[15];
bool cmp (node qwe, node ewq) {
	return qwe.w < ewq.w;
}
int find (int x) {
	if (fu[x] == x) return x;
	return fu[x] = find(fu[x]);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> K;
//	if (k == 0) {
	for (int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
		if (a[i].u > a[i].v) swap(a[i].u, a[i].v);
	} bool kkk = 1;
	for (int i = 1; i <= K; i++) {
		cin >> op[i]; if (op[i] != 0) kkk = 0;
		int fff = 0;
		for (int j = 1; j <= n; j++) {
			cin >> h[j][i];
			if (h[j][i] == 0) fff++;
		}
		if (fff == 0) kkk = 0;
	}
	if (kkk) {
		for (int i = 1; i <= K; i++) {
			for (int j = 1; j <= n; j++) {
				if (h[j][i] == 0) {
					for (int l = 1; l <= n; l++) {
						if (j == l) continue;
						a[++m] = {j, l, h[l][i]};
					}
					break;
				}
			}
		}
	}
	sort (a + 1, a + m + 1, cmp);
	for (int i = 1; i <= n; i++) fu[i] = i;
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (fu[find(a[i].u)] == fu[find(a[i].v)]) continue;
		ans += a[i].w;
//		v[0][a[i].u].push_back({a[i].v, a[i].w});
		b[0][++tot[0]] = {a[i].u, a[i].v, a[i].w};
//		v[0][a[i].v].push_back({a[i].u, a[i].w});
		fu[find(a[i].v)] = fu[find(a[i].u)];
	}
	if (K == 0 || kkk) {
		cout << ans;
		return 0;
	}
	int G = 0;
	sort(b[0] + 1, b[0] + tot[0] + 1, cmp);
	for (int i = n + 1; i <= n + K; i++) { // 忽略不计的常数 
		int ans = 0;
		bool k[M] = {}, B[M] = {}, X[M] = {}, flag = 0;
//		cin >> op[i - n];
//		for (int j = 1; j <= n; j++) cin >> h[j][i - n];
		for (int j = 1; j <= tot[i - n - 1]; j++) { // first
			if (op[i - n] + h[b[i - n - 1][j].u][i - n] + h[b[i - n - 1][j].v][i - n] <= b[i - n - 1][j].w) {
				flag = 1; k[b[i - n - 1][j].u] = 1; k[b[i - n - 1][j].v] = 1;
				ans += b[i - n - 1][j].w - k[b[i - n - 1][j].u] - k[b[i - n - 1][j].v];
				B[j] = 1;
			}
		}
		for (int j = 1; j <= tot[i - n - 1]; j++) { // second
			if (B[j]) continue;
			int xu = 0;
			if (!k[b[i - n - 1][j].u]) xu += h[b[i - n - 1][j].u][i - n];
			if (!k[b[i - n - 1][j].v]) xu += h[b[i - n - 1][j].v][i - n];
			if (xu <= b[i - n - 1][j].w) {
				ans += b[i - n - 1][j].w - k[b[i - n - 1][j].u] - k[b[i - n - 1][j].v];
				B[j] = 1;
				if (!flag && ans >= op[i - n]) {
					ans -= op[i - n]; flag = 1;
				}
			}
		}
			for (int j = 1; j <= tot[i - n - 1]; j++) {
				if (flag && B[j]) {
					if (!X[h[b[i - n - 1][j].u][i - n]]) {
						b[i - n][++tot[i - n]] = {b[i - n - 1][j].u, i, h[b[i - n - 1][j].u][i - n]};
						X[h[b[i - n - 1][j].u][i - n]] = 1;
					}
					if (!X[h[b[i - n - 1][j].v][i - n]]) {
						b[i - n][++tot[i - n]] = {b[i - n - 1][j].v, i, h[b[i - n - 1][j].v][i - n]};
						X[h[b[i - n - 1][j].v][i - n]] = 1;
					}
				} else {
					b[i - n][++tot[i - n]] = b[i - n - 1][j];
				}
			}
//			for (int j = 1; j <= M - 5; j++) {
//				if (B[j]) {
//					b[i - n][++tot[i - n]] = {j, i, h[j]};
//				}
//			}
		ans = 0;
//		cout << flag << " " << tot[i - n] << "\n";
		if (flag) G += op[i - n];
		for (int j = 1; j <= tot[i - n]; j++) {
			ans += b[i - n][j].w;
//			cout << b[i - n][j].w << " ";
		}
//		cout << ans + G << "\n";
	}
	ans = 0;
	for (int i = 1; i <= tot[K]; i++) {
		ans += b[K][i].w;
	}
	cout << ans + G;
//	}
	return 0;
}
// We will win in CSP-S2025!
// We will have 210 pts!
// 15:26 How T2?
// 15:44 Only 20 pts :(
// Go to T3?
// 15:54 I know!
// 16:35 2 AC but 3 4 WA???
// 16:56 T2 Bad? 
// 17:23 T2 20 + 32 + ? !!! 
// We have 162 now! :)
