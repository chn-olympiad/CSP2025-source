#include<bits/stdc++.h>
using namespace std;
const long long MOD = 998244353, N = 505;
long long n, m, c[N], ans, perm[N];
bool vis[N];
string s;

void check() {
	long long lst = 0, hs = 0;
	for (long long i = 1; i <=n; i++) {
		if (s[perm[i]] == '0') {
			lst++;
			continue;
		} else if (lst >= c[perm[i]]) {
			lst++;
			continue;
		} else {
			hs++;
		}
	}
	if (hs >= m){
		ans++;
	}
	ans %= MOD;
	return;
}

void solve(long long x) {
	if (x == n+1) {
		check();
		return;
	}
	for (long long i = 1; i <=n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			perm[x] = i;
			solve(x + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s=' '+s;
	for (long long i = 1; i <= n; i++) cin >> c[i];
	solve(1);
	cout << ans % MOD;
	return 0;
}