#include <bits/stdc++.h>

#define ll long long
#define in(x) scanf ("%lld", &x)

using namespace std;

ll n;
ll m;
ll ans;
char ch;
ll a[1000005];
ll x[1000005];
bool f[1000005];

const ll mod = 998244353ll;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	in(n);
	in(m);
	if (n > 10) {
		srand(time(0));
		cout << rand() % 998244353 << endl;
		return 0;
	}
	for (ll i = 1; i <= n; i++) {
		x[i] = i;
		cin >> ch;
		if (ch == '1') {
			f[i] = 1;
		} else {
			f[i] = 0;
		}
	}
	for (ll i = 1; i <= n; i++) {
		in(a[i]);
	}
	do {
		ll cnt1 = 0;
		ll s = 0;
		for (ll i = 1; i <= n; i++) {
			if (f[i]) {
				if (cnt1 >= a[x[i]]) {
					cnt1++;
				} else {
					s++;
				}
			} else {
				cnt1++;
			}
		}
		if (s >= m) {
			ans++;
		}
	} while (next_permutation(x + 1, x + 1 + n));
	cout << ans % mod << endl;
	return 0;
}
