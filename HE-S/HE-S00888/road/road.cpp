// 为啥最后一个大样例调不过去啊？ 
#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 50, M = 1e6 + 5;
struct Edge {
	long long u, v, w;
};
vector<Edge> ed, g;
long long sp[N]; // 乡村的花费 
long long n, m, k, fa[N], ans, cnt = 1e4 + 99, c, tmp, tmp1;
long long usedd[N];
bool in[N]; // 标记一个乡村是否被用过
long long findd(long long x) {
	if (fa[x] != x)
		fa[x] = findd(fa[x]);
	return fa[x];
}
void uni(long long x, long long y) {
	fa[findd(y)] = findd(x);
}
void kruskal1() {
	sort(g.begin(), g.end(), [](Edge a, Edge b) {
		return a.w < b.w;
	});
	for (long long i = 0; i < g.size(); ++i) {
		long long x = g[i].u, y = g[i].v, w = g[i].w;
		long long r1 = findd(x), r2 = findd(y);
		if (r1 != r2) {
			tmp1 += w;
			uni(r1, r2);
		}
	}
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	scanf("%lld%lld%lld", &n, &m, &k);
	for (long long i = 1; i <= m; ++i) {
		long long u, v, w;
		scanf("%lld%lld%lld", &u, &v, &w);
		if (u <= n && v <= n) {
			ed.push_back((Edge){u, v, w});
			g.push_back((Edge){u, v, w});
			tmp += w;
		}
	}
	for (long long i = 1; i < N - 5; ++i)
		fa[i] = i;
	kruskal1();
	for (long long i = 1; i < N - 5; ++i)
		fa[i] = i;
	for (long long j = 1; j <= k; ++j) {
		long long s;
		scanf("%lld", &s);
		long long x;
		++cnt;
		sp[cnt] = s;
		for (long long i = 1; i <= n; ++i) {
			scanf("%lld", &x);
			ed.push_back((Edge){cnt, i, x + s});
		}
	}
	sort(ed.begin(), ed.end(), [](Edge a, Edge b) {
		return a.w < b.w;
	});
	for (long long i = 0; i < ed.size(); ++i) {
		long long f = true;
		for (long long k = 1e4 + 100; k <= cnt; ++k)
			if (in[k]) f = false;
		if (c == n - 1 && f) break;
		long long x = ed[i].u, y = ed[i].v, w = ed[i].w;
		long long r1 = findd(x), r2 = findd(y);
		if (r1 != r2) {
			ans += w;
			uni(r1, r2);
			++c;
			in[r1] = in[r2] = true;
			if (x >= 1e4 + 100) usedd[x]++;
			if (y >= 1e4 + 100) usedd[y]++;
		}
	}
	for (long long i = 1e4 + 100; i <= cnt; ++i) 
		ans -= sp[i] * usedd[i];
	printf("%lld", min({tmp, ans, tmp1}));
	return 0;
}
