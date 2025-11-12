#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using std::cin;
using std::cout;

int a[500001];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int sum = 0;
	bool flag = true;
	int cnt1 = 0, cnt0 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		if (a[i] != 0 && a[i] != 1) {
			flag = false;
		}
		if (a[i] == 0) {
			cnt0++;
		}
		if (a[i] == 1) {
			cnt1++;
		}
	}
	if (sum == n && k == 0) {
		cout << n / 2;
	}
	else if (flag) {
		if (k == 1) {
			cout << cnt1;
		}
		else if (k == 0) {
			int cnt = 0;
			for (int i = 2; i <= n; i++) {
				if (a[i - 1] == 1 && a[i] == 1) {
					cnt++;
					a[i - 1] = -1;
					a[i] = -1;
				}
				else if (a[i] == 0) {
					cnt++;
					a[i] = -1;
				}
			}
			cout << cnt;
		}
	}
	else if (k == 0) {
		int cnt = 0;
		for (int i = 2; i <= n; i++) {
			if (a[i - 1] == a[i]) {
				cnt++;
				a[i - 1] = -1;
				a[i] = -1;
			}
			else if (a[i] == 0) {
				cnt++;
				a[i] = -1;
			}
		}
		cout << cnt;
	}
	return 0;
}