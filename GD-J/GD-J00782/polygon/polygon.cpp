#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
int a[N], n, ans, sum, maxx;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum += a[i];
		maxx = max(maxx, a[i]);
	}
	if (sum > 2 * maxx) {
		ans ++;
	}
	cout << ans;
	return 0;
}
