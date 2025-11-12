#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	int ans = 0;
	cin >>n;
	int a[5001];
	for (int i = 1; i <= n; i++) {
		cin >>a[i];
	}
	sort(a, a + n);
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			int sum = 0;
			for (int k = j; k <= j + i - 1; k++) {
				sum += a[j];
			}
			int mx = a[j + i - 1];
			if (sum > mx * 2) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
