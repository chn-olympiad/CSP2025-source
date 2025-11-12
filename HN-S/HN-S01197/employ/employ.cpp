#include <bits/stdc++.h>

using namespace std;

const int N = 507, Mod = 998244353;

int n, m, cnt, c[N], a[N], last, ok, num;

long long ans;

string s;

inline
int qpow(int a, int b, int p) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = 1ll * ans * a % p;
		a = 1ll * a * a % p;
		b >>= 1;
	}
	return ans;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) a[i] = i;
	for (int i = 0; i < s.size(); i++) cnt += (s[i] == '1');
	if (cnt == n) {
		ans = 1;
		for (long long i = 2; i <= n; i++) ans = ans * i % Mod;
		cout << ans << '\n';
		return 0;
	}
	do {
		last = 0, ok = 0;
		for (int i = 0; i < n; i++) {
			if (last >= c[a[i + 1]]) {
				last++;
				continue;
			}
			if (s[i] == '0') last++;
			else ok++;
		}
		if (ok >= m) ans++;
	} while (next_permutation(a + 1, a + 1 + n));
	cout << ans << '\n';
	return 0;
}

