#include<bits/stdc++.h>
using namespace std;

int n, m, ans, cnt, s, r;
int a[1005];
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1, a + n*m + 1, cmp);
	for (int i = 1; i <= m * n; i++) {
		if (a[i] == r) {
			ans = i;

			break;
		}
	}
	if (ans <= n) cout << 1 << " " << ans;
	else {
		if (ans % n != 0) {
			int p = ans / n + 1;
			cout << ans / n + 1 << " ";
			if (p % 2 == 0) cout << n - ans % n + 1;
			else cout << ans % n;
		} else {
			cout << ans / n << " ";
			int q = ans / n;
			if (q % 2 == 0) cout << 1;
			else cout << n;
		}
	}
	return 0;
}