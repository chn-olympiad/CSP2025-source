#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 10, U = (1 << 18) + 5, mod = 998244353;
int n, m, c[N], f[U][20];
char v[N];
void solve_dp() {
	scanf("%s", v);
	for(int i = 0; i < n; i ++) scanf("%d", &c[i]);
	f[0][0] = 1;
	for(int S = 0; S < (1 << n) - 1; S ++) {
		int p = __builtin_popcount(S);
		for(int i = 0; i <= p; i ++)
			for(int j = 0; j < n; j ++)
				if(!(S >> j & 1))
					(f[S | (1 << j)][i + ((v[p] - '0') && i > p - c[j])] += f[S][i]) %= mod;
	}
	int res = 0;
	for(int i = m; i <= n; i ++) (res += f[(1 << n) - 1][i]) %= mod;
	printf("%d\n", res);
}
void solve() {

}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	if(n <= 18) solve_dp();
	else solve();
	return 0;
}