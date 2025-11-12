#include <bits/stdc++.h>
using namespace std;
int n, m, c[505], k;
string s;
long long sum, p = 1, h = 998244353;
int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; i++) scanf ("%d", &c[i]);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') k++;
	}
	for (int i = n; i >= n - m + 1; i--) p *= i, p %= h;
	sum = p;
	for (int i = n - m; i >= n - k + 1; i--) {
		p *= i, p %= h, sum += p, sum %= h;
	}
	printf ("%lld", sum);
	return 0;
}
