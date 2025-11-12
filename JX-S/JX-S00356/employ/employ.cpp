#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e2 + 5, P = 20, mod = 998244353;

int c[N], p[N];
int f[1 << P][P];

void solve() {
	int n, m; cin >> n >> m;
	string s; cin >> s; s = ' ' + s;
	for(int i = 1; i <= n; i++)
		cin >> c[i], p[i] = i;
	int ans = 0;
	if(n <= 10) {
		do {
			int cnt = 0, get = 0;
			for(int i = 1; i <= n; i++) 
				if(c[p[i]] <= cnt) cnt++;
				else if(s[i] == '1') get++;
				else cnt++;
			if(get >= m) ans++;
		} while(next_permutation(p + 1, p + 1 + n));
	} else if(n <= 18) {
		f[0][0] = 1;
		for(int i = 0; i < (1 << n); i++) {
			int max_failed = __builtin_popcount(i);
			for(int j = 1; j <= n; j++) {
				if(i & (1 << j - 1)) continue;
				int nxt = i | (1 << j - 1);
				for(int k = 0; k <= max_failed; k++) {
					if(k >= c[j] || s[max_failed + 1] == '0') f[nxt][k + 1] += f[i][k];
					else f[nxt][k] += f[i][k];
				}
			}
		}
		for(int j = 0; j <= n - m; j++)
			ans += f[(1 << n) - 1][j];
	}
	cout << ans % mod << '\n';
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}