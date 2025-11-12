#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define F(i,j,k) for(int i=j;i<=k;i++)
#define D(i,j,k) for(int i=j;i>=k;i--)
#define int long long
bool BEG;
const int N = 5100, mod = 998244353;
int a[N];
int f[N][N];
int fact[N], invfact[N];
int n;
int qpow(int x, int y) {
	int base = x;
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans *= base;
			ans %= mod;
		}
		y >>= 1;
		base *= base;
		base %= mod;
	}
	return ans;
}
int getinv(int x) {
	return qpow(x, mod - 2);
}
int poly(int x, int y) {
	return fact[x] * invfact[x - y] % mod;
}
int comb(int x, int y) {
	int up = poly(x, y);
	int down = invfact[y];
	return up*down % mod;
}
int qzh[N][N];
bool END;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	fact[0] = 1;
	invfact[0] = getinv(fact[0]);
	F(i, 1, N) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		invfact[i] = getinv(fact[i]);
	}
	F(i, 1, N - 1) {
		F(j, 1, i) {
			qzh[i][j] += qzh[i][j - 1];
			qzh[i][j] += comb(i, j);
		}
	}
	cin >> n;
	F(i, 1, n)cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0;
	F(i, 0, N) {
		if (a[1] > i)f[1][i] = 1;
		else f[1][i] = 0;
	}
	F(i, 2, n) {
		F(j, 0, N) {
			if (j - a[i] < 0) {
				f[i][j] = qzh[i - 1][i - 1] + 1;
				f[i][j] += f[i - 1][j];
				f[i][j] %= mod;
			} else {
				f[i][j] = f[i - 1][j];
				f[i][j] += f[i - 1][j - a[i]];
				f[i][j] %= mod;
			}
		}
	}
	F(i, 3, n) {
		int cur = a[i];
		int fa = f[i - 1][cur];
		ans += fa;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
