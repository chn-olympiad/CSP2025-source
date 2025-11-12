#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int n, k, a[MAXN], ans, flag = 1;
int main() {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	scanf ("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) flag = 0;
	}
	if (k == 0 && n <= 2) {
		cout << 1;
		return 0;
	}else if (flag == 0) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == k) ans += 1;
			else {
				if (a[i] == 0) continue;
				if (a[i] == 1) {
					if (a[i + 1] == 1) {
						ans += 1;
						i +=  1;
					}
				}
			}
		}
		cout << ans;
		return 0;
	}else if(flag == 1) {
		cout << n / 2 << endl;
		return 0;
	}
	return 0;
}