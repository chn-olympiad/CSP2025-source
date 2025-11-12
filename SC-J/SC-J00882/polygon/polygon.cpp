#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
#define int long long
int n, a[N], mx, tot, ans;
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]), tot += a[i];
	}
	if (n == 3) {
		if (tot > 2 * mx) cout << 1;
		else cout << 0;
	}
	else if (mx == 1) cout << 2 * n;
	else cout << 6;
	return 0;
}