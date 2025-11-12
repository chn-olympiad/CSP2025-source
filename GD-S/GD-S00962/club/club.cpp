#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 5;

int t, n, ans, cnt[5], l, w[N], f[N], a[N][5];

int Max (int x, int y, int z) {
	return max (max (x, y), z);
}

int Min (int x, int y, int z) {
	return min (min (x, y), z);
}

int Middle (int x, int y, int z) {
	return x + y + z - Max (x, y, z) - Min (x, y, z);
}

signed main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> t;
	while (t --) {
		cin >> n; l = ans = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int t = Max (a[i][1], a[i][2], a[i][3]);
			for (int j = 1; j <= 3; j ++)
				if (a[i][j] == t) f[i] = j;
			ans += t; cnt[f[i]] ++;
		}
		int x = Max (cnt[1], cnt[2], cnt[3]);
		if (x * 2 <= n) {
			cout << ans << "\n"; continue;
		}
		int zzz = 0;
		for (int j = 1; j <= 3; j ++)
			if (cnt[j] == x) zzz = j;
		for (int i = 1; i <= n; i ++) {
			if (f[i] != zzz) continue;
			w[++ l] = Max (a[i][1], a[i][2], a[i][3]) - Middle (a[i][1], a[i][2], a[i][3]);
		}
		sort (w + 1, w + l + 1);
		int m = x - n / 2;
		for (int i = 1; i <= m; i ++) ans -= w[i];
		cout << ans << "\n";
	}
	return 0;
} 
