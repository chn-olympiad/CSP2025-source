#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	cin >> n >> k;
	long long a[200010];
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (k == 1) {
		int ans;
		for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			ans++;
		}
		}
		cout << ans;
		return 0;
	}
	long long sum = 0, sa = 0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = sa; j <= i; j++) {
			sum ^= a[j];
			
		}
		for (int j = sa; j <= i; j++) {
			
			if (sum == k) {
				ans++;
				sum = 0;
				sa = i + 1;
				break;
			}
			sum ^= a[j];
		}
	}
	cout << ans;
	return 0;
}