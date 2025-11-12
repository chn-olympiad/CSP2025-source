#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define ULL unsigned long long
#define LLL __int128
#define Pii pair<int, int>
#define fst first
#define snd second
#define pb push_back
#define endl '\n'

namespace gdb7
{
	constexpr LL MOD = 998244353;
	int a[5010], n;
	LL ans;
	void dfs(int pos, int maxi, int sum, int m) {
		if (pos == n + 1) {
			if (m >= 3 && sum > maxi * 2) {
				++ans;
				if (ans > MOD) ans -= MOD;
			}
			return ;
		}
		dfs(pos + 1, max(maxi, a[pos]), sum + a[pos], m + 1);
		dfs(pos + 1, maxi, sum, m);
	}
	signed main(void) {
		freopen("polygon.in", "r", stdin);
		freopen("polygon.out", "w", stdout);
		int f1 = 1;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] != 1) {
				f1 = 0;
			}
		}
		if (f1) {
			LL ans = 1;
			for (int i = 1; i <= n; ++i) {
				ans *= 2;
				ans %= MOD;
			}
			ans -= 1;
			ans -= n;
			ans -= n * (n - 1) / 2;
			cout << ans << endl;
			return 0;
		}
		if (n <= 20) {
			dfs(1, 0, 0, 0);
			cout << ans << endl;
			return 0;
		}
		return 0;
	}
}

signed main(void)
{
	return gdb7::main();
}

