#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
constexpr int maxn = 1e4 + 10, maxm = 2e6 + 10, maxk = 12;
int dsu[maxm], n, m, k;
int d[maxm], ans;
struct node {
	int u, v, w;
	bool operator < (const node& rhs) {
		return w < rhs.w;
	}
} g[maxm], tmp[maxm], tem[maxm]; int siz;
int ch[maxm];
int cnt;
int N; // 现在树的点数 
int findf (int x) {
	if (x == dsu[x]) return x;
	return dsu[x] = findf(dsu[x]);
}
int Kr () {
	sort(g + 1, g + cnt + 1);
	int Ans = 0, sum = 0;
	for (int i = 1; i <= cnt; i ++) {
		int U = g[i].u, V = g[i].v, W = g[i].w;
		U = findf(U), V = findf(V);
		if (U != V) {
			Ans ++;
			sum += W;
			ch[Ans] = i;
			dsu[U] = V;
		}
		if (Ans == N - 1) break;
	} return sum;
}
int solve (int cost) {
	for (int i = 1; i <= N - 1; i ++) {
		tem[i] = g[i];
	} siz = 0; N ++;
	for (int i = 1; i <= N; i ++) dsu[i] = i;
	for (int i = 1; i <= n; i ++) {
		cnt ++;
		g[cnt].u = N, g[cnt].v = i, g[cnt].w = d[i];
	} int Now = Kr() + cost;
	if (Now > ans) {
		cnt -= n; N --;
		for (int i = 1; i <= N - 1; i ++) {
			g[i] = tem[i];
		}
		return Now;
	}
	for (int i = 1; i <= N - 1; i ++) {
		int pos = ch[i];
		siz ++; tmp[siz] = g[pos];
	}
	for (int i = 1; i <= N - 1; i ++) {
		g[i] = tmp[i];
	} cnt = N - 1;
	return Now;
}
signed main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k; N = n;
	for (int i = 1; i <= n; i ++) dsu[i] = i;
	for (int i = 1; i <= m; i ++) {
		int U, V, W; cin >> U >> V >> W;
		cnt ++; g[cnt].u = U, g[cnt].v = V, g[cnt].w = W;
	} ans = Kr();
	for (int i = 1; i <= n - 1; i ++) {
		int pos = ch[i];
		siz ++; tmp[siz] = g[pos];
	}
	for (int i = 1; i <= n - 1; i ++) {
		g[i] = tmp[i];
	} cnt = n - 1, siz = 0;
	for (int i = 1; i <= k; i ++) {
		int c; cin >> c;
		for (int k = 1; k <= n; k ++)
			cin >> d[k];
		int TTT = solve(c);
		ans = min(ans, TTT);
	} cout << ans;
	return 0;
}
