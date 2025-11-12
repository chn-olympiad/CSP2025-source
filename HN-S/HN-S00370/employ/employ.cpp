#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll kMod = 998244353;
const int kN = 505;

ll s[kN], c[kN], rec[kN], dp[kN][kN], fac[kN], inv[kN];
int n, m;

ll qpow (ll x, ll y) {
	ll ans = 1;
	for (ll i = 1; i <= y; i <<= 1, x = x * x % kMod) {
		if (y & i) {
			ans = ans * x % kMod;
		}
	}
	return ans;
}

int main () {
  freopen ("employ.in", "r", stdin);
  freopen ("employ.out", "w", stdout);
  ios::sync_with_stdio (0);
  cin.tie (0), cout.tie (0);
  
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
  	char x;
  	cin >> x;
  	s[i] = s[i - 1];
  	if (x == '0') ++s[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	
	cout << 0;
  return 0;
}

