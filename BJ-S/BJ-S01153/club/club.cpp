#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0, a[100005];
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> a[0] >> a[0];
		}
		sort(a + 1, a + n + 1);
		for (int i = n; i > n / 2; i--) {
			ans += a[i];
		}
		cout << ans << '\n';
	}
	return 0;
}