#include <bits/stdc++.h>
using namespace std;
int n, a[5005];
bool teshu1, teshu2;
const int mod = 998244353;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n <= 20)
		teshu1 = true;
	teshu2 = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			teshu2 = false;
		}
	}
	if (teshu1) {
		int ans = 0;
		for (int u = 0; u < (1 << n); u++) {
			if (__builtin_popcount(u) < 3)
				continue;
			int nmax = 0, nsum = 0;
			for (int i = 1; i <= n; i++)
				if ((u >> i - 1) & 1) {
					nmax = max(nmax, a[i]);
					nsum += a[i]; 
				} 
			if (nsum > 2 * nmax)
				ans++;
		}
		cout << ans;
	} else if (teshu2){
		int np = 1;
		for (int i = 1; i <= n; i++) {
			np *= 2;
			np %= mod; 
		}
		np -= n;
		if (np < 0)
			np += mod;
		int bb = n * (n - 1) / 2 + 1;
		bb %= mod;
		np -= bb;
		if (np < 0)
			np += mod;
		cout << np;
	}
	return 0;
}
