#include <bits/stdc++.h>
using namespace std;

long long read() {
	long long x = 0, k = 1; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') k = -1, c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x * k;
}

const int N = 2e4 + 7;
const int M = 2e6 + 7;

struct Edge {
	int u, v, w;
	bool operator < (const Edge &x) const {
		return w < x.w;
	}
} e[M];

int n, m, k;
int fa[N], c[N], a[N];

void init() {
	for (int i = 1; i <= n + k; i ++)
		fa[i] = i;
}

int find(int x) {
	return x == fa[x] ? x : (fa[x] = find(fa[x])); 
}

void merge(int x, int y) {
	fa[find(x)] = find(y);
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1, u, v, w; i <= m; i ++) {
		u = read(), v = read(), w = read();
		e[i].u = u, e[i].v = v, e[i].w = w;
	}
	for (int i = 1; i <= k; i ++) {
		c[i] = read();
		for (int j = 1; j <= n; j ++) {
			a[j] = read();
			e[++ m] = (Edge) {i + n, j, a[j]};
		}
	}
	init();
//	for (int i = 1; i <= m; i ++)
//		printf("(%d, %d, %d)\n", e[i].u, e[i].v, e[i].w);
	sort(e + 1, e + m + 1); long long ans = 0;
	for (int i = 1; i <= m; i ++) {
		if (find(e[i].u) != find(e[i].v)) {
//			cout << "?\n";
			ans += e[i].w;
			merge(e[i].u, e[i].v);
		}
	}
	cout << ans << '\n';
	return 0;
}
