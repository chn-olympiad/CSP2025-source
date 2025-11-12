#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MAXN = 1e4 + 5, MAXM = 1e6 + 5, MAXK = 15;
int n, m, k, len, c[MAXK][MAXN], fath[MAXN], tot;

struct Node {
	int x, y, z;
}ls[MAXM + MAXK * MAXN * 4], a[MAXM + MAXK * MAXN * 4];

int get_fath(int x) {
	if (x == fath[x]) return fath[x];
	return fath[x] = get_fath(fath[x]);
}

bool cmp(Node x, Node y) {
	return x.z < y.z;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> ls[i].x >> ls[i].y >> ls[i].z;
		a[i] = ls[i];
	}
	int f = 0;
	for (int i = 1; i <= k; i++) {
		cin >> c[i][0];
		if (c[i][0] != 0) {
			f = 1;
		}
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	if (!f) {
		len = m;
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				for (int l = 1; l <= n; l++) {
					ls[++len].x = j, ls[len].y = l, ls[len].z = c[i][j] + c[i][l];
				}
			}
		}
		for (int i = 1; i <= n; i++) fath[i] = i;
		sort(ls + 1, ls + 1 + len, cmp);
		int cnt = 0, ans = 0;
		for (int i = 1; i <= len && cnt <= n - 1; i++) {
			int u = get_fath(ls[i].x), v = get_fath(ls[i].y);
			if (u != v) {
				ans += ls[i].z;
				fath[v] = u;
				cnt ++;
			}
		}
		cout << ans;
		return 0;
	}
	int sum = 1e18;
	for (int j = 0; j < (1 << k); j++) {
		len = m;
		int ans = 0;
		tot = n;
		for (int i = 1; i <= k; i++) {
			if (((j >> (i - 1)) & 1)) {
				ans += c[i][0];
				++ tot;
				for (int l = 1; l <= n; l++) {
					ls[++len].x = tot, ls[len].y = l, ls[len].z = c[i][l];
				}
			}
		}
		for (int i = 1; i <= tot; i++) fath[i] = i;
		sort(ls + 1, ls + 1 + len, cmp);
		int cnt = 0;
		for (int i = 1; i <= len && cnt <= tot - 1; i++) {
			int u = get_fath(ls[i].x), v = get_fath(ls[i].y);
			if (u != v) {
				ans += ls[i].z;
				if (ans >= sum) break;
				fath[v] = u;
				cnt ++;
			}
		}
		sum = min(sum, ans);
		for (int i = 1; i <= m; i++) ls[i] = a[i];
	}
	cout << sum;
	return 0;
}
