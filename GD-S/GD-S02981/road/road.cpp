#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k, f[10005], c[15], d[15][10005];
struct node{
	int u, v, w;
	bool operator < (const node &A) const {
		return w < A.w;
	}
	bool operator > (const node &B) const {
		return w > B.w;
	}
} g[1000005];
priority_queue<node> q;
bool b[10005], e[15][10005];

int get_f(int x) {
	if (x == f[x]) return x;
	f[x] = get_f(f[x]);
	return f[x];
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &g[i].u, &g[i].v, &g[i].w);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &d[i][j]);
		}
	}
	sort(g + 1, g + m + 1);
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	ll ans = 0, cnt = 0;
	for (int i = 1; i <= m; i++) {
		int fu = get_f(g[i].u);
		int fv = get_f(g[i].v);
		if (fu == fv) continue;
		ans += g[i].w;
		f[fu] = fv;
		cnt++;
		q.push(g[i]);
		if (cnt == n - 1) break;
	}
	if (k == 0) {
		printf("%lld", ans);
		return 0;
	}
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int rr = INT_MAX;
		for (int i = 1; i <= k; i++) {
			int res = 0;
			if (!b[i]) res = c[i];
			b[i] = true;
			int x1 = INT_MAX, x2 = INT_MAX;
			for (int j = 1; j <= n; j++) {
				if (j != f.u && j != f.v) {
					if (get_f(f.u) == get_f(i) || get_f(f.v) == get_f(i)) {
						if (d[i][j] < x1) {
							x2 = x1, x1 = d[i][j];
						} else if (d[i][j] < x2) x2 = d[i][j];
					}
				}
				
			}
			if (x1 < INT_MAX && x2 < INT_MAX) b[i] = true, res += x1 + x2, rr = min(rr, res);
		}
		ans = min(ans, ans - f.w + rr);
	}
	printf("%lld\n", ans);
	return 0;
}
