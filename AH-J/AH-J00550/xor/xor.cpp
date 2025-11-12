#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	bool flag_1 = true;
	bool flag_01 = true;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] != 1) {
			flag_1 = false;
		}
		if (a[i] != 1 && a[i] != 0) {
			flag_01 = false;
		}
	}
	if (flag_1 == true) {
		if (k == 0) {
			int ans = n / 2;
			cout << ans;
		}
		else if(k == 1) {
			cout << n;
		}
		else {
			cout << 0;
		}
		return 0;
	}
	if (flag_01 == true) {
		if (k == 0) {
			int ans = 0;
			for (int i = 1; i < n; i ++) {
				if (a[i] == a[i + 1]) {
					ans ++;
					i ++;
				}
			}
			cout << ans;
		}
		else if(k == 1) {
			int ans = 0;
			for (int i = 1; i <= n; i ++) {
				if (a[i] == 1) {
					ans ++;
				}
			}
			cout << ans;
		}
		else {
			cout << 0;
		}
		return 0;
	}
	else {
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			if(a[i] == k) {
				ans ++;
			}
		}
		cout << ans;
	}
	return 0;
}
