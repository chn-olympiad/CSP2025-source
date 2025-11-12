#include <bits/stdc++.h>

using namespace std;

const int N = 505, MOD = 998244353;

int n, m, s[N], c[N];

long long ans;

int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n >> m;
	string str;
	cin >> str;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		if (c[i])
			++ans;
	}
	if (!ans) {
		cout << 0 << '\n';
		return 0;
	}
	for (long long i = ans - 1; i; --i)
		ans = ans * (ans - 1) % MOD;
	cout << ans << '\n';		
	
	return 0;
}

