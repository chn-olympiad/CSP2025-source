#include <bits/stdc++.h>

using namespace std;

int read() {
    int x = 0, k = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') k = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * k;
}

struct edge {
	int u, v, w;
} a[2000005 << 1];

struct count {
	int cho, w, c[10005];
} b[15];

int n, m, k;
long long ans = 1e16;
int U[1000005], V[1000005], W[1000005];
int fa[20005];

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return 0;
	fa[x] = y; return 1;
}

int special() {
	int ext = n, tot = 0; long long s = 0;
	for (int i = 1; i <= m; i++)
		a[++tot] = {U[i], V[i], W[i]};
	for (int i = 1; i <= k; i++) {
		ext++; s += b[i].w;
		for (int j = 1; j <= n; j++) {
			a[++tot] = {ext, j, b[i].c[j]};
			a[++tot] = {j, ext, b[i].c[j]};
		}
	}
	sort(a + 1, a + tot + 1, cmp);
	for (int i = 1; i <= ext; i++) fa[i] = i;
	int cnt = 0;
	for (int i = 1; i <= tot; i++) {
		if (merge(a[i].u, a[i].v)) {
			cnt++; s += a[i].w;
		}
		if (cnt == ext - 1) break;
	}
	ans = s;
}

void solve() {
	int ext = n, tot = 0; long long s = 0;
	for (int i = 1; i <= m; i++)
		a[++tot] = {U[i], V[i], W[i]};
	for (int i = 1; i <= k; i++) {
		if (b[i].cho == 1) {
			ext++; s += b[i].w;
			for (int j = 1; j <= n; j++) {
				a[++tot] = {ext, j, b[i].c[j]};
				a[++tot] = {j, ext, b[i].c[j]};
			}
		}
	}
	sort(a + 1, a + tot + 1, cmp);
	for (int i = 1; i <= ext; i++) fa[i] = i;
	int cnt = 0;
	
	for (int i = 1; i <= tot; i++) {
		if (merge(a[i].u, a[i].v)) {
			cnt++; s += a[i].w;
		}
		if (cnt == ext - 1) break;
	}
	ans = min(ans, s);
}

void dfs(int p) {
	if (p == k + 1) {
		solve();
		return ;
	}
	b[p].cho = 0; dfs(p + 1);
	if (b[p].w < ans) b[p].cho = 1; dfs(p + 1);
}

int main() {
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++) 
		U[i] = read(), V[i] = read(), W[i] = read();
	for (int i = 1; i <= k; i++) {
		b[i].w = read();
		for (int j = 1; j <= n; j++) 
			b[i].c[j] = read();
	}
	int jud = 1;
	for (int i = 1; i <= k; i++) {
		if (b[i].w != 0) jud = 0;
	}
	if (jud) {
		special(); printf("%lld", ans); return 0;
	}
	dfs(1);
	printf("%lld", ans);
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
