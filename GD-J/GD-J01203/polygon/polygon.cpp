#include <bits/stdc++.h>
using namespace std;

int qh(int m) {
	int n = m + 1;
	long long sum = 0, s = 1, s1 = 1;
	for (int i = 1; i <= n - 1; i++){
		for (int j = i + 1; j <= n - 1; j++) {
			s *= j;
		}
		for (int j = 1; j <= n - 1 - i; j++) {
			s1 *= j;
		}
		sum += s / s1;
	}
	return sum;
}
int a[5005];
int main() {
	int n, ans;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a, a + n);
	int sum;
	for (int i = 3; i <= n; i++) {
		sum = 0;
		int mb = 2 * a[i];
		for (int j = 1; j <= i; j++) {
			sum += a[j];
			if (sum > mb) {
				ans += qh(n - 1) - j;
				break;
			}
		}
	}
	cout << ans % 998244353;
	return 0;
}
