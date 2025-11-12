#include <bits/stdc++.h>
using namespace std;

int a[501], n, m, k, t, ans, cnt;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	k = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == k) {
			t = i;
			break;
		}
	}
	if (t % n == 0) {
		ans = t / n;
		cnt = n;
	} else {
		ans = t / n + 1;
		cnt = t % n;
	}
	if (ans % 2) cout << ans << ' ' << cnt;
	else cout << ans << ' ' << n - cnt + 1;
	return 0;
}
