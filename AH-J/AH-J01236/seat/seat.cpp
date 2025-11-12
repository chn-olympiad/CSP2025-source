#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ll n, m, pm = 1;
	cin >> n >> m;
	ll sc = 0;
	for (int i = 1; i <= n * m; i++) {
		cin >> x;
		if (i == 1)		sc = x;
		if (x > sc)		pm++;
	}
	ll i = pm / n + (pm % n != 0);
	ll j = pm % n;
	if (j == 0) {
		j = n;
	}
	if (i % 2 == 0) {
		j = n - j + 1;
	}
	cout << i << ' ' << j;
	return 0;
}
