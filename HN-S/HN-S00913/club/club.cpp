#include <bits/stdc++.h>
#define int long long

using namespace std;

const int kMaxN = 1e5 + 10;

int b[kMaxN], sum[2][2][2], a[3][kMaxN], t, n, m, cnt;

int C(int id) {
	int cnt1 = sum[1][0][0], cnt2 = sum[0][1][0], cnt3 = sum[0][0][1];
	if (cnt1 > n / 2) {
		return id ? 0 : 1;
	}
	if (cnt2 > n / 2) {
		return id ? 0 : 2;
	}
	if (cnt3 > n / 2) {
		return id ? 0 : 3;
	}
	(cnt1 + sum[1][1][0] > n / 2) && (cnt2 += cnt1 + sum[1][1][0] - n / 2, cnt1 = n / 2);
	if (cnt2 > n / 2) {
		return id ? 0 : 2;
	}
	(cnt1 + sum[1][0][1] > n / 2) && (cnt3 += cnt1 + sum[1][0][1] - n / 2, cnt1 = n / 2);
	if (cnt3 > n / 2) {
		return id ? 0 : 3;
	}
	(cnt2 + sum[0][1][1] > n / 2) && (cnt3 += cnt2 + sum[0][1][1] - n / 2, cnt2 = n / 2);
	return (cnt3 <= n / 2 ? 1 : (id ? 0 : 3));
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (cin >> t; t--; m = cnt = 0, memset(sum, 0, sizeof sum)) {
		cin >> n;
		for (int i = 1, x; i <= n; i++) {
			cin >> a[0][i] >> a[1][i] >> a[2][i], x = max(a[0][i], max(a[1][i], a[2][i])), sum[x == a[0][i]][x == a[1][i]][x == a[2][i]]++, cnt += x;
		}
		if (C(1)) {
			cout << cnt << '\n';
		} else {
			int id = C(0);
			for (int i = 1, x; i <= n; i++) {
				x = max(a[0][i], max(a[1][i], a[2][i])), (x == a[id - 1][i]) && (b[++m] = a[id - 1][i] - max(a[id % 3][i], a[(id + 1) % 3][i]));
			}
			sort(b + 1, b + 1 + m);
			for (int i = 1; i <= m - n / 2; i++) {
				cnt -= b[i];
			}
			cout << cnt << '\n';
		}
	}
	return 0;
}
