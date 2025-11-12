#include <bits/stdc++.h>
#define ri register int

using namespace std;
typedef long long ll;

constexpr int mod = 998244353;

int n, m;
char s[505];
int c[505];

ll ans = 0;

bool f[505];
int a[505];

inline void dfs(int x) {
	if(x > n) {
		int cnt = 0;
		for(ri i = 1; i <= n; ++i) {
			int p = a[i];
			if(s[i] == '0' || cnt >= c[p]) ++cnt;
		}
		if(n - cnt >= m) ++ans;
		return ;
	}
	for(ri i = 1; i <= n; ++i) {
		if(f[i]) continue;
		f[i] = 1;
		a[x] = i;
		dfs(x + 1);
		f[i] = 0;
	}
}

inline void Solve() {
	cin >> n >> m;
	cin >> (s + 1);
	for(ri i = 1; i <= n; ++i) cin >> c[i];
	int cnt = 0;
	for(ri i = 1; i <= n; ++i) {
		if(s[i] == '0') {
			++cnt;
		}
	} 
	if(n <= 10) dfs(1);
	else {
		if(m == 1) {
			ans = 0;
		}
		else if(m == n) {
			bool flag = 1;
			for(ri i = 1; i <= n; ++i) {
				if(s[i] == '0') {
					flag = 0;
					break;
				}
			} 
			if(flag) {
				ans = 1;
				for(ri i = 1; i <= n; ++i) {
					ans = ans * i % mod;
				}
			}
			else ans = 0;
			
		}
	}
	if(cnt == 0) {
		ans = 1;
		for(ri i = 1; i <= n; ++i) {
			ans = ans * i % mod;
		}
		return cout << ans << "\n", void();
	}
	cout << ans << "\n";
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	Solve();
	return 0;
}

