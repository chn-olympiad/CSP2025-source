#include <bits/stdc++.h>
#define int long long
using namespace std;

bool s[505];
int c[505];

const int mod = 998244353;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	int n, m; cin >> n >> m;
	int ans = 1;
	for (int i = 1; i <= n; i++) ans = ans * i % mod;
	cout << ans;
	return 0;
}

