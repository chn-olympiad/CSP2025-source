#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	int cnt1 = 0, cnt0 = 0;
	cin >> a[1];
	int x = 0;
	int ans = -1;
	if (x == k) {
		ans = 1;
	}
	for (int i = 2; i <= n; ++i) {
		cin >> a[i];
		x ^= a[i];
		if (x == k) {
			ans = i;
		}
		if (a[i] == 1) cnt1++;
		else if (a[i] == 0) cnt0++;
	}
	if (k == 0) {
		if (cnt1 + cnt0 == n) cout << n;
		else cout << 1;
	} else {
		cout << ans;
	} 
	return 0;
}