#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
typedef long long ll;
inline int read() {int x; return scanf("%d", &x), x;}
inline int read1() {int x; return scanf("%1d", &x), x;}
namespace solve
{
	const int N = 5e2;
	const int mod = 998244353;
	inline int add(int a, int b) {return a + b >= mod ? a + b - mod : a + b;}
	inline void upd(int &a, int b) {a = add(a, b);}
	int _C[N + 5][N + 5], _A[N + 5][N + 5];
	inline void init()
	{
		for (int i = 0; i <= N; i ++ ) _C[i][i] = _C[i][0] = 1;
		for (int i = 1; i <= N; i ++ )
			for (int j = 1; j < i; j ++ )
				_C[i][j] = add(_C[i - 1][j], _C[i - 1][j - 1]);
		_A[0][0] = 1;
		for (int i = 1; i <= N; i ++ )
		{
			_A[i][0] = 1;
			for (int j = 1; j <= i; j ++ ) _A[i][j] = (ll)_A[i][j - 1] * (i - j + 1) % mod;
		}
	}
	inline int C(int n, int m) {return m < 0 || n < m ? 0 : _C[n][m];}
	inline int A(int n, int m) {return m < 0 || n < m ? 0 : _A[n][m];}
	int s[N + 5], c[N + 5];
	int sum[N + 5];
	int dp[2][N + 5][N + 5];
	int main()
	{
		init();
		int n = read(), m = read();
		for (int i = 1; i <= n; i ++ ) s[i] = read1();
		for (int i = 1; i <= n; i ++ ) c[i] = read(), sum[c[i]] ++ ;
		for (int i = 1; i <= n; i ++ ) sum[i] += sum[i - 1];
		dp[0][0][0] = 1;
		for (int i = 1; i <= n; i ++ )
		{
			std :: memset(dp[i & 1], 0, sizeof dp[i & 1]);
			for (int j = 0; j <= i; j ++ )
				for (int k = 0; k <= std :: min(i, sum[j]); k ++ )
				{
					if (!s[i])
					{
						if (!j) break;
						for (int l = 0; l <= std :: min(k, sum[j] - sum[j - 1]); l ++ )
						{
							if (l < k && sum[j - 1] - k + l >= 0) upd(dp[i & 1][j][k], (ll)C(sum[j] - sum[j - 1], l) * dp[i - 1 & 1][j - 1][k - l - 1] % mod * A(i - k + l, l) % mod * (sum[j - 1] - k + l + 1) % mod);
							upd(dp[i & 1][j][k], (ll)C(sum[j] - sum[j - 1], l) * l % mod * dp[i - 1 & 1][j - 1][k - l] % mod * A(i - k + l - 1, l - 1) % mod);
							upd(dp[i & 1][j][k], (ll)C(sum[j] - sum[j - 1], l) * dp[i - 1 & 1][j - 1][k - l] % mod * A(i - k + l - 1, l) % mod);
						}
					}
					else
					{
						if (j)
						{
							for (int l = 0; l <= std :: min(k - 1, sum[j] - sum[j - 1]); l ++ )
								if (sum[j - 1] - k + l >= 0) upd(dp[i & 1][j][k], (ll)C(sum[j] - sum[j - 1], l) * dp[i - 1 & 1][j - 1][k - l - 1] % mod * A(i - k + l, l) % mod * (sum[j - 1] - k + l + 1) % mod);
						}
						upd(dp[i & 1][j][k], dp[i - 1 & 1][j][k]);
					}
				}
		}
		int res = 0;
		for (int i = 0; i <= n - m; i ++ ) upd(res, (ll)dp[n & 1][i][sum[i]] * A(n - sum[i], n - sum[i]) % mod);
		printf("%d\n", res);
		return 0;
	}
}
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
#endif
	int T = 1;
	while (T -- ) solve :: main();
	return 0;
}