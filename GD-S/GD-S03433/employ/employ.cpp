#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 510, mod = 998244353;
int s[maxn], c[maxn], p[maxn];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int mn = 1;
	char ch;
	for (int i = 1; i <= n; i++) cin >> ch, s[i] = ch - '0', mn = min(mn, s[i]);
	for (int i = 1; i <= n; i++) cin >> c[i];
	if (mn == 1) {
		int tmp = n;
		for (int i = 1; i <= n; i++) if (!c[i]) tmp--;
		ll ans = 1;
		for (int i = 1; i <= tmp; i++) ans = ans * i % mod;
		cout << ans;
		exit(0);
	}
	for (int i = 1; i <= n; i++) p[i] = i;
	ll ans = 0;
	do {
		int fail = 0;
		for (int i = 1; i <= n; i++) {
			if (!s[i]) fail++;
			else if (fail >= c[p[i]]) fail++;
		}
		if (n - fail >= m) ans++;
	} while (next_permutation(p + 1, p + n + 1));
	cout << ans;
	return 0;
}

