#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstdio>
#define endl '\n'
using namespace std;
namespace IO {
	inline int Read() {
		int x = 0, k = 0; char ch = getchar();
		while (!isdigit(ch)) k |= (ch == '-'), ch = getchar();
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ '0'), ch = getchar();
		return k ? -x : x;
	}
}
const int MaxN = 1E4 + 10;
const int MaxM = 1E6 + 10;
const int MaxK = 15;
int k, m, n, M, N;
long long ans;
int fa[MaxN + MaxK];
long long val[MaxK];
long long cost[MaxK][MaxN];
struct Edge {
	int u, v;
	long long w;
	inline bool operator < (const Edge &A) const { return w < A.w; }
}b[MaxM], e[MaxM], g[MaxM];
inline int Find(int u) {
	return fa[u] == u ? u : (fa[u] = Find(fa[u]));
}
void KruskalInit() {
	for (register int i = 1; i <= n; i++) fa[i] = i;
	sort(e + 1, e + m + 1);
	for (register int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		u = Find(u), v = Find(v);
		if (u == v) continue;
		fa[u] = v, ans += w;
		g[++N] = e[i];
	}
}
long long Kruskal() {
	for (register int i = 1; i <= k + n; i++) fa[i] = i;
	sort(b + 1, b + M + 1);
	long long sum = 0;
	for (register int i = 1; i <= M; i++) {
		int u = b[i].u, v = b[i].v, w = b[i].w;
		u = Find(u), v = Find(v);
		if (u == v) continue;
		fa[u] = v, sum += w;
	}
	return sum;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = IO::Read(), m = IO::Read(), k = IO::Read();
	for (register int i = 1; i <= m; i++) {
		e[i].u = IO::Read(), e[i].v = IO::Read(), e[i].w = IO::Read();
	}
	for (register int i = 1; i <= k; i++) {
		val[i] = IO::Read();
		for (register int j = 1; j <= n; j++) cost[i][j] = IO::Read();
	}
	KruskalInit();
	for (register int sta = 0; sta <= (1 << k) - 1; sta++) {
		for (register int i = 1; i <= N; i++) b[i] = g[i];
		long long sum = 0;
		M = N;
		for (register int i = 1; i <= k; i++) {
			if ((sta >> (i - 1)) & 1) {
				sum += val[i];
				for (register int j = 1; j <= n; j++) b[++M] = (Edge){ i + n, j, cost[i][j] };
			}
		}
		sum += Kruskal();
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}

