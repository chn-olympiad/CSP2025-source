#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int kMaxN = 1e4 + 50, kMaxM = 1e6 + 5;

struct node {
	ll v;
	int id;
}a[15][kMaxN];

struct edge{
	int u, v;
	ll w;
}tr[kMaxN], e[kMaxM], tmp[kMaxM];

int n, m, k, cnt, vil, f[kMaxN], c[15];
ll ans;

bool cmp(edge a, edge b) {
	return a.w < b.w;
}

bool cmp2(node a, node b) {
	return a.v < b.v;
}

int find(int x) {
	return (f[x] == x ? x : f[x] = find(f[x]));
}

ll Kruskal(int m) {
	ll sum = 0;
	for (int i = 1; i <= n + k; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++) {
		int x = find(e[i].u), y = find(e[i].v);
		if (x != y) {
			sum += e[i].w;
			f[x] = y;
		}
	}
	return sum;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++) {
		int x = find(e[i].u), y = find(e[i].v);
		if (x != y) {
			ans += e[i].w;
			tr[++cnt] = e[i];
			f[x] = y;
		}
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j].v, a[i][j].id = j;
		sort(a[i] + 1, a[i] + n + 1, cmp2);
	}
	for (int i = 0; i < (1 << k); i++) {
		ll sum = 0;
		cnt = n - 1, vil = 0;
		for (int j = 1; j <= cnt; j++)
			e[j] = tr[j];
		for (int j = 1; j <= k; j++)
			if (i & (1 << (j - 1))) {
				sum += c[j];
				vil++;
				int now = 0, x = 1, y = 1;
				for (; y <= cnt; ) {
					if (x > n || a[j][x].v > e[y].w)
						tmp[x + y - 1] = e[y], y++;
					else
						tmp[x + y - 1] = {n + vil, a[j][x].id, a[j][x].v}, x++;
				}
				cnt = x + y - 2;
				for (int a = 1; a <= cnt; a++)
					e[a] = tmp[a];
			}
		ans = min(ans, Kruskal(cnt) + sum);
	}
	cout << ans;
	return 0;
}
// cute zrr let me ac plz 
