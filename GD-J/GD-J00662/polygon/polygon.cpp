#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 998244353;
int n, a[5010], maxn;
ll cnt, num;
bool is_po (ll sum, ll max) {
	if (sum > max * 2) return 1;
	return 0;
}
int main() {
	freopen ("a.in", "r", stdin);
	freopen ("a.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		num += a[i];
		maxn = max (maxn, a[i]);
	}
	if (n == 3 && is_po (num, maxn)) cout << 1;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
