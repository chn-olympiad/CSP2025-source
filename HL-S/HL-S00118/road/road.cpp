#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e4;
constexpr int M = 1e6;
constexpr int K = 10;

int n, m, k, u[M + 1], v[M + 1], w[M + 1], c[K + 1], a[K + 1][N + 1];
int id[M + 1], fa[N + K + 1], cnt[1 << K];
array<int, 3> info[K + 1][N + K], tree[1 << K][N + K], tmp[N * 2 + K * 2];

int get_fa(int node) {
	if (fa[node] == node)
		return node;
	else
		return fa[node] = get_fa(fa[node]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> u[i] >> v[i] >> w[i];
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			info[i][j] = array<int, 3>{n + i, j, a[i][j]};
		}
		sort(info[i] + 1, info[i] + 1 + n, [](array<int, 3> u, array<int, 3> v) {
			return u[2] < v[2];
		});
	}
	iota(id + 1, id + 1 + m, 1);
	iota(fa + 1, fa + 1 + n + k, 1);
	sort(id + 1, id + 1 + m, [](int u, int v) {
		return w[u] < w[v];
	});
	long long ans = 0;
	for (int i = 1; i <= m; i++)
		if (get_fa(u[id[i]]) != get_fa(v[id[i]])) {
			fa[get_fa(u[id[i]])] = get_fa(v[id[i]]);
			tree[0][++cnt[0]] = array<int, 3>{u[id[i]], v[id[i]], w[id[i]]};
			ans += w[id[i]];
		}
	for (int i = 1; i < (1 << k); i++) {
		int id = -1;
		for (int j = 1; j <= k; j++)
			if (i >> (j - 1) & 1) {
				id = j;
				break;
			}
		int lst = i ^ (1 << (id - 1));
		int ct = 0, p = 1, q = 1;
		while (p <= cnt[lst] && q <= n) {
			if (tree[lst][p][2] < info[id][q][2])
				tmp[++ct] = tree[lst][p++];
			else
				tmp[++ct] = info[id][q++];
		}
		while (p <= cnt[lst])
			tmp[++ct] = tree[lst][p++];
		while (q <= n)
			tmp[++ct] = info[id][q++];
		iota(fa + 1, fa + 1 + n + k, 1);
		long long total = 0;
		for (int j = 1; j <= ct; j++) {
			if (get_fa(tmp[j][0]) != get_fa(tmp[j][1])) {
				fa[get_fa(tmp[j][0])] = get_fa(tmp[j][1]);
				total += tmp[j][2];
				tree[i][++cnt[i]] = tmp[j];
			}
		}
		for (int j = 1; j <= k; j++)
			total += c[j] * (i >> (j - 1) & 1);
		ans = min(ans, total);
//		cerr << i << ": ";
//		for (int j = 1; j <= cnt[i]; j++)
//			cerr << tree[i][j][0] << ',' << tree[i][j][1] << ',' << tree[i][j][2] << " \n"[j == cnt[i]];
	}
	cout << ans << '\n';
	return 0;
}