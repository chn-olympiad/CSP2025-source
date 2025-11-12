#include<bits/stdc++.h>
using namespace std;
unsigned  long long ans = 0;
long long n, a[100005];
unsigned long long b[100005];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if (n < 3) {
		cout << 0;
	} else if (n == 3) {
		int a, b, c;
		cin >> a >> b >> c;
		int m = max(a, b);
		m = max(m, c);
		if (a + b + c > 2 * c) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; ++i) {
			b[i] = b[i - 1] + a[i];
		}
		for (int l = 1; l <= n - 2; ++l) {
			for (int r = l + 2; r <= n; ++r) {
				long long h = b[r] - b[l];
				if (h > 2 * a[r]) {
					ans++;
					cout << l << " " << r << '\n';
					ans = ans % 998244353;
				}
			}
		}
		cout << ans;
	}
	return 0;
}