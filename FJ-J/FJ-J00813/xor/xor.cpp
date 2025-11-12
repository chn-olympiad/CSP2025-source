#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll num1, num0;
int main() {
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	ll n, k, a;
	cin >> n >> k;
	for (ll i = 1; i <= n; i ++) {
		cin >> a;
		if (a == 1) num1 ++;
		if (a == 0) num0 ++;
	}
	if (num1 == n && k == 0) cout << n / 2;
	else if (k == 1) cout << num1;
	else if (k == 0) cout << num0;
	else cout << 0;
	return 0;
}
