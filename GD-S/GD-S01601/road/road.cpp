#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#define LL long long
#define int long long

using namespace std;

int read() {
	int k = 0, kk = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			kk = -1;
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		k = k * 10 + c - '0';
		c = getchar();
	}
	return k * kk;
}

void write(int x) {
	if (x < 0)
		putchar('-'), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

const int N = 1e4 + 10, M = 4e6 + 10, K = 52, Inf = 1e18;

int n, m, k;
struct node {
	int u, v, w;
} e[M];
int tot;
int g[1010][1010];
int c[K];
int a[K][N];
int anc[N];

int find(int x) {
	return anc[x] == x? x : anc[x] = find(anc[x]);
}

bool cmp(node a, node b) {
	return a.w < b.w;
}

int get() {
	for (int i = 1; i <= n; i ++ )
		anc[i] = i;
	int ans = 0, cnt = n;
	sort(e + 1, e + tot + 1, cmp);
	for (int i = 1; i <= tot; i ++ ) {
		int fx = find(e[i].u), fy = find(e[i].v);
		if (fx == fy)
			continue;
		anc[fx] = fy, ans += e[i].w, cnt -- ;
		if (cnt == 1)
			break;
	}
	return ans;
}

void k0() {
	for (int i = 1; i <= m; i ++ ) {
		int u = read(), v = read(), w = read();
		e[++ tot] = node {u, v, w};
	}
	write(get());
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	if (!k) {
		k0();
		return 0;
	}
	for (int i = 1; i <= n; i ++ )
		for (int j = i + 1; j <= n; j ++ )
			g[i][j] = g[j][i] = ++ tot, e[tot] = node {i, j, Inf};
	for (int i = 1; i <= m; i ++ ) {
		int u = read(), v = read(), w = read();
		e[g[u][v]].w = min(e[g[u][v]].w, w);
	}
	for (int i = 1; i <= k; i ++ ) {
		c[i] = read();
		for (int j = 1; j <= n; j ++ )
			a[i][j] = read();
	}
	int cnt = 0, ans = Inf;
	for (int i = 0; i <= k; i ++ ) {
		if (i) {
			cnt += c[i];
			for (int j = 1; j <= n; j ++ )
				for (int k = j + 1; k <= n; k ++ ) 
					e[g[j][k]].w = min(e[g[j][k]].w, a[i][j] + a[i][k]);
		}
		ans = min(ans, get() + cnt);
	}
	write(ans);
	return 0;
}
