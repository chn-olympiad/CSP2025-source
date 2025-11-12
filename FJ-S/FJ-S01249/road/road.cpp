#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline int read1() {
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

inline ll read2() {
	ll x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}

const int N = 1e4 + 10;
const int M = 1e6 + 10;
int n, m, k, tot, cnt;
ll a[N][N], b[N], ans;
int f[N];
struct edge {
	int u, v;
	ll w;
}e[M];

bool cmp(const edge& a, const edge& b) {
	return a.w < b.w;
}

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read1(), m = read1(), k = read1();
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int u = read1(), v = read1();
		ll w = read2();
		a[u][v] = min(a[u][v], w);
		a[v][u] = min(a[v][u], w);
	}
	for (int i = 1; i <= k; i++) {
		ll c = read2();
		for (int j = 1; j <= n; j++) {
			b[j] = read2();
		}
		for (int k = 1; k <= n; k++) {
			for (int j = 1; j <= n; j++) {
				if (k == j) continue;
				a[k][j] = min(a[k][j], c + b[k] + b[j]);
				a[j][k] = min(a[j][k], c + b[k] + b[j]);
			}
		}
		
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i][j] != 0x3f3f3f3f3f3f3f3f) {
				e[++tot].u = i;
				e[tot].v = j;
				e[tot].w = a[i][j];
			}
		}
	}
	sort(e + 1, e + 1 + tot, cmp);
	for (int i = 1; i <= tot; i++) {
		int fu = find(e[i].u), fv = find(e[i].v);
		if (fu != fv) {
			f[fu] = fv;
			cnt++;
			ans += e[i].w;
		}
		if (cnt == n - 1) {
			printf("%lld", ans);
			return 0;
		}
	}
	return 0;
}