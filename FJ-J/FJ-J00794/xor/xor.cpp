#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], flag = 0;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a == 0) flag = 1;
	}
	if (flag) {
		if (k == 1) {
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) cnt++;
			}
			cout << cnt; 		
		} else {
			int cnt1 = 0, cnt2 = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 0) cnt1++;
				else if (a[i] == 1 && (a[i - 1] == 1 || a[i + 1] == 1)) cnt2++;
			}
			cout << cnt1 + cnt2 / 2;
		}

	} else {
		cout << n / 2;
	}
	return 0;
}
