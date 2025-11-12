#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
struct edge {
	long long u, v, w;
} e[2000010], e2[2000010];
long long f[20010], tmp[20010], c[20], d[20][20010];
long long get(long long i) {
	if (f[i] == i) return i;
	return (f[i] = get(f[i]));
}
void merge(long long i, long long j) {
	long long xx = get(i), yy = get(j);
	f[xx] = yy;
}
long long ans;
void krus() {
	int cnt = n - 1;
	for (long long i = 1; i <= m; i++) {
		if (get(e[i].u) != get(e[i].v)) {
			cnt--;
			merge(e[i].u, e[i].v);
			ans += e[i].w;
			if (cnt == 0) break;
		}
	}
}
bool cmp(edge x, edge y) {
	return x.w < y.w;
}
void dfs(long long dep, long long stat) {
	if (dep > k) {
		long long res = 0, cnt = n - 1;
		long long len = m;
		for (long long i = 1; i <= m; i++) e2[i] = e[i];
		for (long long i = 1; i <= k; i++) {
			if (!(stat & (1 << (i - 1)))) continue;
			res += c[i];
			cnt += stat & (1 << (i - 1));
			for (long long j = 1; j <= n; j++) e2[++len] = {j, n + i, d[i][j]};
		}
		sort(e2 + 1, e2 + len + 1, cmp);
		for (long long i = 1; i <= n + 15; i++) f[i] = i;
		for (long long i = 1; i <= len; i++) {
			if (get(e2[i].u) != get(e2[i].v)) {
				cnt--;
				merge(e2[i].u, e2[i].v);
				res += e2[i].w;
				if (cnt == 0) break;
			}
		}
		ans = min(ans, res);
		return;
	}
	dfs(dep + 1, stat << 1);
	dfs(dep + 1, (stat << 1) + 1);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (long long i = 1; i <= n; i++) f[i] = i;
	for (long long i = 1; i <= m; i++) cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + m + 1, cmp);
	krus();
	for (long long i = 1; i <= k; i++) {
		cin >> c[i];
		for (long long j = 1; j <= n; j++) cin >> d[i][j];
	}
	if (pow(2, k) * m * 10 <= 1e8) {
		dfs(1, 0);
		cout << ans;
		return 0;
	}
	for (long long i = 1; i <= k; i++) {
		long long len = m;
		for (long long i = 1; i <= m; i++) e2[i] = e[i];
		for (long long j = 1; j <= n; j++) e2[++len] = {j, n + 1, d[i][j]};
		sort(e2 + 1, e2 + len + 1, cmp);
		for (long long i = 1; i <= n + 1; i++) f[i] = i;
		long long res = c[i], cnt = n;
		for (long long i = 1; i <= len; i++) {
			if (get(e2[i].u) != get(e2[i].v)) {
				cnt--;
				merge(e2[i].u, e2[i].v);
				res += e2[i].w;
				if (cnt == 0) break;
			}
		}
		ans = min(ans, res);
	}
	cout << ans;
	return 0;
}
