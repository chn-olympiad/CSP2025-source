#include <bits/stdc++.h>

using namespace std;

constexpr int N = 500;
constexpr int M = 500;
constexpr int P = 998244353;

int n, m, c[N + 1];
string s;
int f[1 << 18][19];

int case_1_to_5() {
	f[0][0] = 1;
	for (int i = 0; i < (1 << n); i++)
		for (int j = 0; j <= n; j++)
			if (f[i][j]) {
				cerr << i << ' ' << j << ' ' << f[i][j] << '\n';
				for (int k = 1; k <= n; k++)
					if ((i >> (k - 1) & 1) == 0) {
						if (j < c[k])
							(f[i ^ (1 << (k - 1))][j + '1' - s[__builtin_popcount(i)]] += f[i][j]) %= P;
						else
							(f[i ^ (1 << (k - 1))][j + 1] += f[i][j]) %= P;
					}
			}
	int ret = 0;
	for (int i = 0; i < (1 << n); i++)
		if (n - i >= m)
			(ret += f[(1 << n) - 1][i]) %= P;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
//	cerr << s << '\n';
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	if (n <= 18)
		cout << case_1_to_5() << '\n';
	return 0;
}