#include <bits/stdc++.h>
#define ll long long
//#define int long long
using namespace std;

const int N = 510, mod = 998244353;
int n, m, c[N], pre[N], suf[N];
int f[2][N][N];
char s[N];
int fac[N], C[N][N], A[N][N];
void init() {
	fac[0] = 1;
	for (int i=1; i<=n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
	for (int i=0; i<=n; ++i) {
		C[i][0] = 1;
		for (int j=1; j<=i; ++j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	for (int i=0; i<=n; ++i)
		for (int j=0; j<=n; ++j) A[i][j] = 1ll * C[i][j] * fac[j] % mod;
}
void add(int &x, ll y) {
	x = (x + y) % mod;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s + 1);
	init();
	for (int i=1,x; i<=n; ++i) {
		scanf("%d", &x); ++c[x];
	}
	for (int i=0; i<=n; ++i) pre[i] = (i ? pre[i - 1] : 0) + c[i];
	for (int i=n; i>=0; --i) suf[i] = suf[i + 1] + c[i];
	f[0][0][0] = 1;
	for (int i=0; i<n; ++i)
		for (int x=0; x<=i; ++x)
			for (int k=0; k<=i; ++k) if (f[i & 1][x][k]) {
				int tmp = f[i & 1][x][k], r = ((i & 1) ^ 1);
				if (s[i + 1] == '0') {
					for (int l=0; l<=min(c[x+1],k+1); ++l)
						add(f[r][x + 1][k + 1 - l], 1ll * tmp * C[c[x + 1]][l] % mod * A[k + 1][l]);
				}
				if (pre[x] - i + k > 0) {
					for (int l=0; l<=min(c[x+1],k); ++l)
						add(f[r][x + 1][k - l], 1ll * tmp * (pre[x] - i + k) % mod * C[c[x + 1]][l] % mod * A[k][l]);
				}
				if (s[i + 1] == '1') add(f[r][x][k + 1], tmp);
				f[i & 1][x][k] = 0;
			}
	int ans = 0;
	for (int x=0; x<=n-m; ++x) {
		int tmp = f[n & 1][x][suf[x + 1]];
	//	printf("x %lld f %lld\n", x, tmp);
		add(ans, 1ll * tmp * fac[suf[x + 1]]);
	}
	cout << ans << "\n";
	return 0;
}