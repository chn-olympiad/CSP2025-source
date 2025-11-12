#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,m;
int s[510];
int c[510];
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	int sum = 0;
	for (int i = 1 ; i <= n ; i++)
	{
		char abc;
		cin >> abc;
		s[i] = abc - '0';
		sum += s[i];
	}
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> c[i];
	}
	if (m > sum)
	{
		cout << 0;
	}
	else
	{
		if (m == 1)
		{
			sort(c + 1,c + n + 1);
		}
		if (m == n)
		{
			sort(c + 1,c + n + 1);
			if (c[1] == 0)
			{
				cout << 0;
			}
			else
			{
				int ans = 1;
				for (int i = 1 ; i <= n ; i++)
				{
					ans *= i;
					ans %= P;
				}
				cout << ans;
			}
		}
	}
	return 0;
} 
