#include <bits/stdc++.h>
using namespace std;
long long int n,m[5005],x,f,sum,cnt;
__int128 c = 1;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> m[i];
		if (i == 1)
		{
			x = m[i];
		}
		else
		{
			if (x != m[i])
			{
				f = 1;
			}
		}
	}
	if (f == 0)
	{
		for (long long int i = 3;i <= n;i++)
		{
			x = min(i,n - i);
			for (int j = n - x + 1;j <= n;j++)
			{
				c = c * j / (j - n + x);
			}
			c %= 998244353;
			sum = (sum + c) % 998244353;
			c = 1;
		}
		cout << sum; 
	}
	else
	{
		sort(m + 1,m + n + 1);
		cout << cnt;
	}
	return 0;
}
