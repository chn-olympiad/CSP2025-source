#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 100, maxm = 2e6 + 10;
struct Edge {
	int s, t;
	long long v;
}e[maxm];
bool usv[20];
int f[maxn], n, m, k, len, cho;
long long c[20], ans = 1e18;
int Find(int x) {
	if (x == f[x]) return x;
	return f[x] = Find(f[x]);
}
long long solve(int s) {
	memset(usv, 0, sizeof usv);
	int con = 1, siz = n;
	long long res = 0;
	for (int i = 0; i < k; i++) if (s & (1 << i)) usv[i + 1] = 1, siz ++, res += c[i];
	for (int i = 1; i <= n + k; i++) f[i] = i;
	for (int i = 0; i < len; i++) {
		if (con == siz) break;
		if (e[i].t > n && !usv[e[i].t - n]) continue;
		if (Find(e[i].s) != Find(e[i].t)) f[Find(e[i].s)] = Find(e[i].t), con++, res += e[i].v;
	}
	return con == siz ? res : 1e18;
}
bool cmp(Edge A, Edge B) {
	return A.v < B.v;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) scanf("%d%d%lld", &e[i].s, &e[i].t, &e[i].v);
	for (int i = 0; i < k; i++) {
		scanf("%lld", c + i);
		for (int j = 1; j <= n; j++) {
			long long v; scanf("%lld", &v);
			e[m + n * i + j - 1] = {j, n + i + 1, v};
		}		
	}
	len = m + k * n;
	sort(e, e + len, cmp);
	int up = (1 << k);
	for (int i = 0; i < k; i++) if (!c[i]) cho += (1 << i); //骗性质 A
	for (int i = 0; i < up; i++) if ((cho & i) == cho) ans = min(ans, solve(i));
	printf("%lld\n", ans);
	return 0;
}