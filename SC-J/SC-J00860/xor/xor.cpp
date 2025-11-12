#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
long long n, k, a[N], ans, l, r, s[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	l = r = 1;
	while (l <= r && r <= n) {
		if ((s[r] ^ s[l - 1]) == k) {
			ans++;
			r++;
			l = r;
		} else {
			r++;
		}
	}
	cout << ans;
	return 0;
}