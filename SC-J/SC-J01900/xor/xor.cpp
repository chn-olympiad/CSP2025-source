#include<bits/stdc++.h>
using namespace std;
long long n, k, x, flag, flag2, a[1000010], ans;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x > 1) flag = 1;
		if (x == 0) flag2 = 1;
		a[i] = x;
	}
	if (!flag && !flag2) cout << n / 2;
	else if (!flag && flag2) {
		for (int i = 1; i <= n; i++) {
			if(a[i] == 1 && k == 1) ans++;
			if(a[i] == 0 && k == 0) ans++;
		}
		cout << ans;
	}
}