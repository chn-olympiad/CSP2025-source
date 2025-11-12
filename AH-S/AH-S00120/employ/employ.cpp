#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 500;
const int Mod = 998244353;
int n, m, c[N + 10];
string str;
namespace solve1 {
	const int N = 18;
	int f[(1 << N) + 10][N + 3];
	void upd(int &x, int y) {
		x = (x + y) % Mod;
	}
	void solve() {
		f[0][0] = 1;
		for(int S = 0; S < (1 << n); S++) {
			int i = __builtin_popcount(S) + 1;
			for(int x = 0; x <= i; x++)
			for(int y = 0; y < n; y++) {
				if(!((S >> y) & 1)) {
					if(str[i] == '0') upd(f[S | (1 << y)][x + 1], f[S][x]);
					else {
						if(c[y + 1] <= x) upd(f[S | (1 << y)][x + 1], f[S][x]);
						else upd(f[S | (1 << y)][x], f[S][x]);
					}
				}
			}
		}

		int ans = 0;
		for(int i = 0; i <= n; i++)
			if(n - i >= m)
				upd(ans, f[(1 << n) - 1][i]);
		cout << ans << '\n';
	}
}
namespace solve2 {
	void solve() {
		int res = 1;
		for(int i = 1; i <= n; i++)
			res = 1ll * res * i % Mod;
		cout << res << '\n';
	}
}
ll ans = 0;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> str; str = "#" + str;
	for(int i = 1; i <= n; i++) cin >> c[i];
	if(n <= 18) solve1::solve();
	else solve2::solve();
}