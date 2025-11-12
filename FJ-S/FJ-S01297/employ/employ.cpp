#include <bits/stdc++.h>
using namespace std;

const int N = 510, M = 25, T = (1 << 18) + 10, mod = 998244353;

int n, m;
char s[N];
int sum[N], c[N];
int f[T][M];

int get1(int x)
{
	int res = 0;
	while (x) res ++ , x -= (x & -x);
	return res;
}

void sub1()
{
	sort(c + 1, c + 1 + n);
	int cnt0 = 0, cnt1 = 0, res = 1, mul = 1;
	for (int i = 1; i <= n; i ++ ) mul = 1ll * mul * i % mod; 
	for (int i = 1, j = 1; i <= n; i ++ )
	{
		if (s[i] == '0') {cnt0 ++ ; continue;}
		while (j <= n && c[j] <= i - 1) j ++ ;
		if (j - 1 == cnt1) {printf("%d\n", mul); return;}
		res = 1ll * res * (j - 1 - cnt1) % mod, cnt1 ++ ;
	}
	for (int i = 1; i <= cnt0; i ++ ) res = 1ll * res * i % mod;
	printf("%d\n", 1ll * (1ll * mul - 1ll * res + mod) % mod);
}

void subn()
{
	bool flag = true;
	for (int i = 1; i <= n; i ++ )
	{
		if (s[i] == '0' || !c[i]) {flag = false; break;}
	}
	if (!flag) {printf("0\n"); return;}
	int res = 1;
	for (int i = 1; i <= n; i ++ ) res = 1ll * res * i % mod;
	printf("%d\n", res);
}

void suba() {}

void solve()
{
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; i ++ ) scanf("%d", &c[i]);
	if (m == 1) {sub1(); return;}
	if (m == n) {subn(); return;}
//	bool flag = true;
//	for (int i = 1; i <= n; i ++ ) flag &= (s[i] == '1');
//	if (flag) {suba(); return;}
	f[0][0] = 1;
	for (int i = 0; i < (1 << n); i ++ )
	{
		int cnt = get1(i);
		for (int j = 0; j <= cnt; j ++ )
			for (int k = 1; k <= n; k ++ )
			{
				if ((i >> (k - 1)) & 1) continue;
				int nxti = (i | (1 << (k - 1))), nxtj = j;
				if (s[cnt + 1] == '0' || j >= c[k]) nxtj ++ ;
				f[nxti][nxtj] = (f[nxti][nxtj] + f[i][j]) % mod;
			}
	}
	int res = 0;
	for (int i = 0; i <= n - m; i ++ ) res = (res + f[(1 << n) - 1][i]) % mod;
	printf("%d\n", res);
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int T = 1;
	while (T -- ) solve();
	return 0;
}
