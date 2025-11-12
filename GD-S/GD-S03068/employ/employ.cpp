#include <bits/stdc++.h>
namespace GDS03068 {
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
typedef pair<ll, pair<int, int>> pip;
#define fi first
#define se second
const int maxn = 5e2 + 20, mod = 998244353;
int n, m, ms;
ll ans;
string s;
int c[maxn];
int f[1 << 22][22];
void init() {
}
void Mian() {
	init();
	cin >> n >> m >> s;
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	int c0 = 0;
	for (int i = 0; i < n; ++i)
		c0 += (c[i] == 0);
	if (c0 > n - m) {
		cout << "0\n";
		return;
	}
	f[0][0] = 1;
	ms = (1 << n) - 1;
	for (int S = 1; S <= ms; ++S) {
		int maf = __builtin_popcount(S);
		for (int fai = 0; fai < maf; ++fai) {
			for (int T = S, i, x; T; T ^= x) {
				x = T & -T, i = __lg(x);
				if (!f[S ^ x][fai]) continue;
				if (s[maf - 1] == '0' || fai >= c[i])
					(f[S][fai + 1] += f[S ^ x][fai]) %= mod;
				else (f[S][fai] += f[S ^ x][fai]) %= mod;
			}
		}
	}
	for (int i = n - m; i >= 0; --i)
		(ans += f[ms][i]) %= mod;
	cout << ans << '\n';
}
}
int main() {
#ifndef LOCALruanhuaxuan
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	int T = 1;
//	std::cin >> T;
	while (T--) GDS03068::Mian();
	return 0;
}

