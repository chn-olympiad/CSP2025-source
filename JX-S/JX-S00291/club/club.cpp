#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 410;
inline int read()
{
	char c; int sign = 1, res = 0;
	while((c = getchar()) > '9' || c < '0')
	{
		if(c == '-') sign = -1;
	}
	while(c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * sign;
}
int dp[M][M][M], a[M][4];
int res = 0;
int n; 
int rt;
void solve()
{
	memset(dp, 0, sizeof(dp));
	res = 0;
	n = read();
	bool flag = 1;
	for(int i = 1; i <= n; i++)
	{
		a[i][1] = read();
		a[i][2] = read();
		a[i][3] = read();
		if(a[i][2] > 0 || a[i][3] > 0) flag = 0;
	}
	if(flag)
	{
		for(int i = 1; i <= n; i++)
			res += a[i][1];
		cout << res << endl;
		return;
	}
	int w = n / 2;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= w; j++)
		{
			for(int k = 0; k <= w; k++)
			{
				if(i - k - j > w) continue;
				//cout << i << " " << j << " " << k << " " << i - j - k << endl;
				if(i - j - k < 0) break;
				if(j > 0) dp[j][k][i - j - k] = max(dp[j][k][i - j - k], dp[j - 1][k][i - j - k] + a[i][1]);
				if(k > 0) dp[j][k][i - j - k] = max(dp[j][k][i - j - k], dp[j][k - 1][i - j - k] + a[i][2]);
				if(i - j - k > 0) dp[j][k][i - j - k] = max(dp[j][k][i - j - k], dp[j][k][i - j - k - 1] + a[i][3]);
			}
		}
	}
	for(int i = 0; i <= (n >> 1); i++)
	{
		for(int j = 0; j <= (n >> 1); j++)
		{
			for(int k = 0; k <= (n >> 1); k++)
			{
				if(i + j + k > n) break;
				res = max(res, dp[i][j][k]);
			}
		}
	}
	//cout << dp[2][3][1] << endl;
	cout << res << endl;
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	T = read();
	while(T--)
	{
		//cout << 1;
		solve();
	}
	return 0;
}
/*
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
 * */

