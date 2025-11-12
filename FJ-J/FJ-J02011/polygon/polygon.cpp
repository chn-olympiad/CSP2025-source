#include<bits/stdc++.h>
using namespace std;
long long n, a[5005], ans, b[5005], sum, u, vis[5005], l, r, mid, t, flag = 1;
int finds (int x) {
	l = 1, r = n;
	while (l < r - 1) {
		mid = (l + r + 1) / 2;
		if (a[mid] > x) r = mid;
		else if (a[mid] < x) l = mid;
		else break;
	}
	mid = (l + r + 1) / 2;
	if (a[mid] <= x) {
		while (a[mid] <= x) {
			mid++;
			if (a[mid] == 0) break;
		}
		mid--;
	}
	else while (a[mid] > x) {
		mid--;
		if (a[mid] == 0) break;
	}
	return mid;
}
void dfs (int x, int m) {
	if (x > n) return;
	b[x] = a[m];
	if (x >= 3) {
		sum = u = 0;
		for (int i = 1; i <= x; i++) sum += b[i], u = max (u, b[i]);
		if (sum > 2 * u) ans++, ans %= 998244353;
	}
	for (int i = m + 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			dfs (x + 1, i);
			vis[i] = 0;
		}
	}
}
int main () {
//	freopen ("polygon4.in", "r", stdin);
//	freopen ("polygon4.out", "w", stdout);
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		u = a[1];
		if (a[i] != u) flag = 0;
	}
	if (n == 3) {
		if (a[1] + a[2] + a[3] > 2 * max (a[1], max(a[2], a[3]))) cout << 1;
		else cout << 0;
		return 0;
	}
	if (n <= 10) {
		dfs (0, 0);
		cout << ans % 998244353;
		return 0;
	}
	if (flag) {
		for (int i = 3; i <= n; i++) {
			t = 1;
			if (2 * i <= n) {
				for (int j = n - i + 1; j <= n; j++) {
					t *= j;
					t %= 998244353;
				}
				for (int j = 1; j <= i; j++) t /= j;
			}
			else {
				for (int j = i + 1; j <= n; j++) {
					t *= j;
					t %= 998244353;
				}
				for (int j = 1; j <= n - i; j++) t /= j;
			}
			ans += t;
			ans %= 998244353;
		}
		cout << ans;
		return 0;
	}
//	sort (a + 1, a + n + 1);
//	cout << finds (5);
	dfs (0, 0);
	cout << ans % 998244353;
	return 0;
}
