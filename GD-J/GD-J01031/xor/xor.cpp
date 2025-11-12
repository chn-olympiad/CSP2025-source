#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
long long n, k, op, a[N], ans[N][N], mx = 0;

int main()
{
	#ifdef LOCAL
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	#endif
	cin >> n >> k;
	for(long long i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	for(long long i = 1; i <= n; i ++)
	{
		for(long long j = i; j <= n; j ++)
		{
			if(i == j)
			{
				ans[i][j] = ans[i][j - 1];
			}
			ans[i][j] ^= a[j];
		}
	}
	for(long long i = 1; i <= n - 1; i ++)
	{
		for(long long j = i; j <= n - 1; j ++)
		{
			for(long long x = j + 1; x <= n; x ++)
			{
				for(long long y = x; y <= n; y ++)
				{
					if(ans[i][j] == ans[x][y] && ans[i][j] == k)
					{
						mx = max(mx, j - i + 1 );
						mx = max(mx, y - x + 1);
					}
				}
			}
		}
		if(i * n * (n - 1) * (n - 1) > 1e9)
		{
			break;
		}
	}
	cout << mx;
}
