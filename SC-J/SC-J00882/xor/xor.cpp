#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
#define int long long
int n, k, a[N], mx, mi = 1e9, f;
int sc(int x) {
	int p = 1, sum = 0;
	while (x > 0) {
		sum += (x % 2) * p;
		p *= 10, x /= 2;
	}
	return sum;
}
int yh(int x, int y) {
	int a = sc(x), b = sc(y), sum = 0, now = 1;
	while (a > 0 || b > 0) {
		int p = a % 10, q = b % 10;
		if (p != q) sum += now;
	}
	return sum;
}
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		mi = min(mi, a[i]);
		if (a[i] == 0) f = 1;
	}
	if (mx == mi && mx == 1) {
		if (n <= 2) {
			if (n == 1) cout << 0;
			else cout << 1;
		}
		else {
			if (k == 0) cout << n / 2;
			if (k == 1) cout << n;
			if (k > 1) cout << 0;
		}
	}
	else {
		int sum = a[1], cnt = 0;
		for (int i = 2; i <= n; i++) {
			sum = yh(sum, a[i]);
			if (sum == k) {
				cnt++, sum = a[i + 1];
				i += 2;
			}
		}
		cout << cnt;
	}
	return 0;
}