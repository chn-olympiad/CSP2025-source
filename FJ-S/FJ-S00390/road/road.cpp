#include <bits/stdc++.h>
using namespace std;

inline int read() {
	int x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	x = ch ^ 48, ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x;
}

const int N = 1e4 + 5, M = 1e6 + 5;
int arr[M], idx;	// ÀëÉ¢»¯ 
int n, m, k, tot;
struct Edges { int u, v, w; } e[M], t[M];
inline bool cmp(Edges a, Edges b) { return a.w < b.w; }
vector< Edges > use;
int c[15], a[15][N];

int p[N];
inline int find(int x) { return (p[x] == x) ? x : p[x] = find(p[x]); }
long long ans;

vector< Edges > qwq[N * 12];
inline bool chk(int S, int i) { return (S >> i) & 1; }
void check(int S) {
	long long sum = 0; tot = 0;
	for (Edges it : use) t[++tot] = it;
	for (int i = 1; i <= k; i++) if (chk(S, i - 1)) {
		sum += c[i];
		for (int j = 1; j <= n; j++) t[++tot] = (Edges){i + n, j, a[i][j]};
	}
	for (int i = 1; i <= n + k; i++) p[i] = i;
	
	for (int i = 1; i <= tot; i++) qwq[t[i].w].push_back(t[i]);
	tot = 0;
	for (int i = 1; i <= idx; i++) {
		for (Edges it : qwq[i]) t[++tot] = it;
		qwq[i].clear();
	}
//	sort(t + 1, t + 1 + tot, cmp);

	for (int i = 1; i <= tot; i++) {
		int x = find(t[i].u), y = find(t[i].v);
		if (x == y) continue;
		p[x] = y, sum += arr[t[i].w];
	}
	ans = min(ans, sum);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read(), use.clear();
	for (int i = 1; i <= m; i++) e[i].u = read(), e[i].v = read(), e[i].w = read();
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++) a[i][j] = read(), arr[++idx] = a[i][j];
	}
	sort(e + 1, e + 1 + m, cmp);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i++) {
		int x = find(e[i].u), y = find(e[i].v);
		if (x == y) continue;
		p[x] = y, use.push_back(e[i]);
		arr[++idx] = e[i].w;
	}

	// ÀëÉ¢»¯ 
	sort(arr + 1, arr + 1 + idx), idx = unique(arr + 1, arr + 1 + idx) - arr - 1;
	for (int i = 0; i < (int)use.size(); i++) use[i].w = lower_bound(arr + 1, arr + 1 + idx, use[i].w) - arr;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++) a[i][j] = lower_bound(arr + 1, arr + 1 + idx, a[i][j]) - arr;
	
	ans = 1e18;
	for (int S = 0; S < (1 << k); S++) check(S);
	printf("%lld\n", ans);
	return 0;
}
