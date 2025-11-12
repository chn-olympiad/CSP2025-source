#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
int a[N], n;

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	bool all_one = true;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] != 1) all_one = false;
	}
	if(n == 3) {
		int mx = max(a[1], max(a[2], a[3]));
		if(a[1] + a[2] + a[3] > 2 * mx) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	if(n == 4) {
		int ans = 0;
		for(int i = 1; i <= n - 2; i++) {
			for(int j = i + 1; j <= n - 1; j++) {
				for(int k = j + 1; k <= n; k++) {
					int mx = max(a[i], max(a[j], a[k]));
					if(a[i] + a[j] + a[k] > 2 * mx) {
						ans++;
					}
				}
			}
		}
		int mx = max(max(a[1], a[2]), max(a[3], a[4]));
		if(a[1] + a[2] + a[3] + a[4] > 2 * mx) {
			ans++;
		}
		cout << ans; 
	}
	if(all_one) {
		int ans = 0;
		for(int i = 3; i <= n; i++) {
			ans += n - i + 1;
			ans %= 998244353;
		}
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	
	return 0;
}
