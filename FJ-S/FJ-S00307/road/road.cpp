#include <bits/stdc++.h>
using namespace std;

const long long N = 10010, M = 2000010;
long long n, m, k, fa[N], sz, a[20][N], c[20], b[N];
bool vis[N];
struct Edge{
	long long u, v, w;
	bool operator< (const Edge B) const {
		return w < B.w;
	}
}e[M], gt[M], t[M];

struct edge {
	long long v, w;
};

struct Node {
	long long x, d;
	bool operator< (const Node B) const {
		return d > B.d;
	}
};

long long read() {
	long long x = 0, f = 1; char c = getchar();
	while ('0' > c || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while ('0' <= c && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

long long find(long long x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

long long lowbit(long long x) { return x & -x; }

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (long long i = 1; i <= n; i++) fa[i] = i;
	for (long long i = 1; i <= m; i++) {
		long long u = read(), v = read(), w = read();
		e[i] = {u, v, w};
	}
	bool flag = true;
	for (long long i = 1; i <= k; i++) {
		c[i] = read();
		if (c[i] != 0) flag = false;
		for (long long j = 1; j <= n; j++)
			a[i][j] = read();
	}
	if (flag) {
		for (long long i = n + 1; i <= n + k; i++) fa[i] = i;
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++)
				e[++m] = {i + n, j, a[i][j]};
		}
		sort(e + 1, e + m + 1);
		long long tmp = 0;
		for (long long i = 1; i <= m; i++) {
			long long u = e[i].u, v = e[i].v, w = e[i].w;
			long long rx = find(u), ry = find(v);
			if (rx != ry) fa[rx] = ry, gt[++sz] = {u, v, w}, tmp += w;
		}
		printf("%lld", tmp);
		return 0;
	}
	sort(e + 1, e + m + 1);
	long long tmp = 0;
	for (long long i = 1; i <= m; i++) {
		long long u = e[i].u, v = e[i].v, w = e[i].w;
		long long rx = find(u), ry = find(v);
		if (rx != ry) fa[rx] = ry, gt[++sz] = {u, v, w}, tmp += w;
	}
	long long ans = tmp;
	if (k == 0) { printf("%lld", tmp); return 0; }
	for (long long S = 1; S < (1 << k); S++) {
		memset(b, 0x3f, sizeof b);
		vector<edge> g[N];
		long long T = S;
		long long res = 0;
		while (T) {
			long long x = lowbit(T);
			T ^= x;
			long long i = log2(x) + 1;
			res += c[i];
			for (int j = 1; j <= n; j++)
				g[i + n].push_back({j, a[i][j]}),
				g[j].push_back({i + n, a[i][j]});
		}
		if (res >= ans) continue;
		
		for (long long i = 1; i < n; i++)
			g[e[i].u].push_back({e[i].v, e[i].w}),
			g[e[i].v].push_back({e[i].u, e[i].w});
		priority_queue<Node> q;
		q.push({1, 0});
		memset(vis, 0, sizeof vis);
		while (q.size()) {
			Node TTT = q.top(); q.pop();
			long long u = TTT.x, d = TTT.d;
			if (vis[u]) continue;
			vis[u] = true;
			res += d;
			for (edge TT : g[u]) {
				long long v = TT.v, w = TT.w;
				if (vis[v]) continue;
				q.push({v, w});
			}
		}
		ans = min(ans, res);
	}
	printf("%lld", ans);
	return 0;
}
