#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[114514];
int p[114514];
int n, K;


inline int sum(int l, int r)
{
	return p[l - 1] ^ p[r];
}


int dp[5001][5001];

int solveNN()
{
	for (int len = 1; len <= n; ++len)
	{
		for (int i = 1; i + len - 1 <= n; ++i)
		{
			int j = i + len - 1;
			dp[i][j] = (sum(i, j) == K);
			for (int k = i; k < j; ++k)
			{
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
			}
		}
	}
//	for (int i = 1; i <= n; ++i)
//	{
//		for (int j = 1; j <= n; ++j)
//		{
//			cerr << dp[i][j] << ' ';
//		}
//		cerr << '\n';
//	}
	return dp[1][n];
}

signed main()
{
	ifstream cin("xor.in");
	ofstream cout("xor.out");

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> K;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		p[i] = p[i - 1] ^ a[i];
	}
	
	cout << solveNN();
}
