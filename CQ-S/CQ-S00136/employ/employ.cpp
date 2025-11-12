#include <stdio.h>
const int mod = 998244353;
class modInt
{
public:
	int val;
	modInt(void) : val(0) {}
	modInt(int v) : val(v) {}
	modInt& operator+=(const modInt& other) { return (val += other.val) >= mod ? val -= mod, *this : *this; }
	modInt operator+(const modInt& other) { return modInt(val + other.val >= mod ? val + other.val - mod : val + other.val); }
	modInt operator*(const modInt& other) { return modInt(val * (long long)(other.val) % mod); }
} fac[505], invFac[505], dp[3][505][505];
bool s[505];
int n, m, cc[505], precc[505];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	fac[0] = invFac[0] = invFac[1] = 1;
	for (int i = 1; i <= n; ++i)
		fac[i] = fac[i - 1] * i;
	for (int i = 2; i <= n; ++i)
		invFac[i] = invFac[mod % i] * (mod - mod / i);
	for (int i = 2; i <= n; ++i)
		invFac[i] = invFac[i - 1] * invFac[i];
	for (int i = 1; i <= n; ++i)
	{
		char c = getchar();
		while (c == '\n' || c == '\r' || c == ' ')
			c = getchar();
		s[i] = c == '1';
	}
	for (int i = 1, c; i <= n; ++i)
	{
		scanf("%d", &c);
		++cc[c];
	}
	precc[0] = cc[0];
	for (int i = 1; i <= n; ++i)
		precc[i] = precc[i - 1] + cc[i];
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= i; ++j)
			for (int k = 0; k <= i; ++k)
				dp[1][j][k] = dp[2][j][k] = 0;
		for (int j = 0; j < i; ++j)
			for (int k = 0; k < i && k <= precc[j]; ++k)
			{
				modInt now = dp[0][j][k];
				dp[1][j + 1][k + 1] += now * (precc[j] - k);
				if (s[i])
					dp[2][j][k] += now;
				else
					dp[1][j + 1][k] += now;
			}
		for (int j = 0; j <= i; ++j)
			for (int k = 0; k <= i && k <= precc[j]; ++k)
			{
				dp[0][j][k] = dp[2][j][k];
				for (int l = 0; l <= k && l <= cc[j]; ++l)
				{
					dp[0][j][k] += dp[1][j][k - l] * fac[i - k + l] * fac[cc[j]] * invFac[i - k] * invFac[cc[j] - l] * invFac[l];
				}
			}
	}
	modInt ans;
	for (int i = n - m; i >= 0; --i)
		ans += dp[0][i][precc[i]] * fac[n - precc[i]];
	printf("%d\n", ans.val);
	return 0;
}