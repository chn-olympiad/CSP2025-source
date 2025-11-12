#include <bits/stdc++.h>
using namespace std;
const long long INF = 998244353;
long long ans, a[5010], sum[5010];
void search(long long k, int l, int r) {
	for (int i = l; i <= r; i++) {
		if (a[i] < k) {
			ans++;
			search(k - a[i], i + 1, r);
		}
	}
}
signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	} 
	sort(a + 1, a + n + 1);
	for (int i = 3; i <= n; i++) {
		if (sum[i - 1] <= a[i]) {
			continue;
		}
		ans++;
		search(sum[i - 1] - a[i], 1, i - 1);
		ans %= INF;
	}
	cout << ans;
}

