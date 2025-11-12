#include <bits/stdc++.h>
using namespace std;
#define maxn 505
const int mod = 998244353;
int n, m;
char s[maxn];
int sum[maxn], s2[maxn], fact[maxn];
int c[maxn];
int dp[maxn][maxn][maxn];
int C[maxn][maxn];
void add(int &x, int y)
{
	x += y, x %= mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	C[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	cin >> s + 1;
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = 1ll * fact[i - 1] * i % mod;
	for (int i = 1; i <= n; ++i) cin >> c[i], s2[c[i]]++;
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + (s[i] == '0');
	for (int i = 1; i <= n; ++i) s2[i] += s2[i - 1];
	if(n - sum[n] < m)
	{
		cout << 0 << endl;
		return 0;
	}
	dp[0][0][s2[0]] = 1;
	int num = 0;
	for (int i = 1; i <= n; ++i)
	{
		num += s[i] == '1';
		if(s[i] == '0')
		{
			for (int j = 0; j <= num; ++j)
			{
				for (int k = 0; k <= n; ++k)
				{
					if(dp[i - 1][j][k] == 0) continue;
//					cout << i - 1 << " " << j << " " << k << endl;
					int _new = s2[j + sum[i]] - s2[j + sum[i] - 1];
					int l = i - 1 - (s2[j + sum[i] - 1] - k);
					for (int ll = 0; ll <= _new && ll <= l + 1; ++ll)
					{
						add(dp[i][j][k + _new - ll], dp[i - 1][j][k] * 1ll * C[_new][ll] % mod * C[l + 1][ll] % mod);
						if(k && ll != l + 1) add(dp[i][j][k + _new - ll - 1], dp[i - 1][j][k] * 1ll * C[_new][ll] % mod * k % mod * C[l][ll] % mod);
					}
				}
			}
		}
		else
		{
			for (int j = 0; j <= num - 1; ++j)
			{
				for (int k = 0; k <= n; ++k)
				{
					if(dp[i - 1][j][k] == 0) continue;
					int _new = s2[j + sum[i] + 1] - s2[j + sum[i]];
					//可行
					add(dp[i][j][k], dp[i - 1][j][k]);
					//不可行
					int l = i - 1 - (s2[j + sum[i]] - k);
					if(k)
					for (int ll = 0; ll <= _new && ll <= l; ++ll) add(dp[i][j + 1][k + _new - ll - 1], dp[i - 1][j][k] * 1ll * C[_new][ll] % mod * k % mod * C[l][ll] % mod);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; ++i) if(i + sum[n] <= n - m)
	{
		add(ans, dp[n][i][0]);
	}
	cout << ans << endl;
	return 0;
}

