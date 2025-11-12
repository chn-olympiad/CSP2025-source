#include <bits/stdc++.h>
using namespace std;

long long read() {
	long long x = 0, k = 1; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') k = -1, c = getchar();
	while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return x * k;
}

#define int long long

const int N = 1e5 + 7;

int n;
int a[N][3], gg[N], ggid[N], id[4];
int c[N], tot;
int cnt[3];

void solve() {
	n = read(); long long ans = 0;
	for (int i = 0; i < 3; i ++)
		cnt[i] = id[i] = 0;
	for (int i = 1; i <= n; i ++) {
		gg[i] = 0;
		for (int x = 0; x < 3; x ++)
			a[i][x] = read();
		id[0] = 0, id[1] = 1, id[2] = 2;
		sort(id, id + 3, [&](int x, int y) {
			return a[i][x] < a[i][y];
		});
		ans += a[i][id[2]];
		gg[i] = a[i][id[2]] - a[i][id[1]];
		ggid[i] = id[2];
		cnt[id[2]] ++; 
	}
	int wjc = max({cnt[0], cnt[1], cnt[2]}) - n / 2, pid = 0;
	for (int i = 0; i < 3; i ++)
		if (cnt[i] == wjc + n / 2) pid = i;
	tot = 0;
	for (int i = 1; i <= n; i ++)
		if (ggid[i] == pid)
			c[++ tot] = gg[i];
	sort(c + 1, c + tot + 1);
	for (int i = 1; i <= wjc; i ++)
		ans -= c[i];
	cout << ans << '\n';
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t = read();
	while (t --)
		solve();
	return 0;
}


