#include <bits/stdc++.h>

using namespace std;

const long long N = 505, mod = 998244353;

long long n, m, s[N], c[N], ans, fac[N];

char ch[N];

bool vis[N];

void Dfs(long long x, long long o) {
	if (o >= m) {
		ans += fac[n - x + 1];
		ans %= mod; 
		return;
	}
	if (x > n) {
		return;
	}
	long long dis = x - o - 1;
	for (long long i = 1; i <= n; i++) {
	    if (!vis[i]) {
	    	vis[i] = 1;
	    	Dfs(x + 1, o + ((s[x] == 1) && (dis < c[i])));
	    	vis[i] = 0;
		}		
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	bool flag = 0;
	fac[0] = 1;
	for (long long i = 1; i <= n; i++) {
		cin >> ch[i];
		s[i] = ch[i] - '0';
		if (s[i] == 0) {
			flag = 1;
		}
		fac[i] = (fac[i - 1] * i % mod) % mod;
	}
	for (long long i = 1; i <= n; i++) {
		cin >> c[i]; 
	}
//	if (flag) {
		Dfs(1, 0);
		ans %= mod;
		cout << ans;
		return 0;
//	}
//	cout << fac[n];
	return 0;
} 
