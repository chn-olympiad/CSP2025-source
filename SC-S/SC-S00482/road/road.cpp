#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 50, M = 1e6 + 10, K = 15;
int n, tot, m, k, ptr, siz, c[K], a[K][N], f[N];
struct Edge {
	int u, v, w;
	bool operator < (const Edge cmp) const {
		return w < cmp.w;
	}
} eg[M], rem[M], eg2[M];

int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

void merge(int u, int v) {
	u = find(u), v = find(v);
	f[v] = u;
}

bool isdiff(int u, int v) { return find(u) != find(v); }

void kruskal() {
	sort(eg + 1, eg + m + 1);
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 1; i <= m; ++i)
		if (isdiff(eg[i].u, eg[i].v)) {
			merge(eg[i].u, eg[i].v);
			rem[++ptr] = eg[i];
		}
}

int kruskal2() {
	int res = 0;
	sort(eg2 + 1, eg2 + siz + 1);
	for (int i = 1; i <= tot; ++i) f[i] = i;
	int p1 = 1, p2 = 1, cnt = tot;
	while ((p1 <= ptr || p2 <= siz) && cnt > 1) {
		Edge e;
		if (p1 > ptr) e = eg2[p2++];
		else if (p2 > siz) e = rem[p1++];
		else {
			if (eg2[p2] < rem[p1]) e = eg2[p2++];
			else e = rem[p1++];
		}
		if (isdiff(e.u, e.v)) {
			merge(e.u, e.v);
			res += e.w;
			--cnt;
		}
	}
	return res;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		eg[i] = { u, v, w };
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	}
	kruskal();
	int ans = LLONG_MAX;
	for (int s = 0; s < (1 << k); ++s) {
		tot = n;
		siz = 0;
		int sum = 0;
		for (int i = 1; i <= k; ++i)
			if ((s << 1 >> i) & 1) {
				++tot;
				sum += c[i];
				for (int j = 1; j <= n; ++j)
					eg2[++siz] = { tot, j, a[i][j] };
			}
		int tmp = kruskal2();
//		printf("%lld : %lld + %lld = %lld\n", s, tmp, sum, tmp + sum);
		ans = min(ans, tmp + sum);
	}
	printf("%lld\n", ans);
	fclose(stdin), fclose(stdout);
	return 0;
}