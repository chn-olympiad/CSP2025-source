#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL mod = 998244353;
const int maxn = 505;
int n, m, c[maxn];
LL f[1 << 20][20], ans = 0;
char s[maxn];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> (s + 1);
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	if (n <= 20) {
		f[0][0] = 1;
		for (int S = 0; S < (1 << n); S++) {
			int cnt = 0;
			for (int i = 1; i <= n; i++)
				if (S & (1 << (i - 1)))
					cnt++;
			for (int i = 0; i <= cnt; i++) {
				for (int nxt = 1; nxt <= n; nxt++) {
					if (S & (1 << (nxt - 1))) continue;
					if (s[cnt + 1] == '1' && i < c[nxt])
						f[S + (1 << (nxt - 1))][i] = (f[S + (1 << (nxt - 1))][i] + f[S][i]) % mod;
					else
						f[S + (1 << (nxt - 1))][i + 1] = (f[S + (1 << (nxt - 1))][i + 1] + f[S][i]) % mod;
				}
			}
		}
		for (int i = 0; i <= n - m; i++)
			ans = (ans + f[(1 << n) - 1][i]) % mod;
		cout << ans << '\n';
		return 0;
	}
	if (m == n) {
		int flag = 1;
		for (int i = 1; i <= n; i++)
			if (s[i] == '0' || c[i] == 0)
				flag = 0;
		if (!flag) cout << 0 << '\n';
		else {
			ans = 1;
			for (int i = 1; i <= n; i++)
				ans = (ans * i) % mod;
			cout << ans << '\n';
		}
		return 0;
	}
	ans = 1;
	for (int i = 1; i <= n; i++)
		ans = (ans * i) % mod;
	cout << ans << '\n';
	return 0;
}