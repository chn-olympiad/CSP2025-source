#include <bits/stdc++.h>
using namespace std;

long long a[500005], s[1003][1003];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	bool fa = true, fb = true;
	int n;
	long long k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		
		if (a[i] != 1)
		{
			fa = false;
		}
		
		if (a[i] > 1)
		{
			fb = false;
		}
	}
	
	if (fa)
	{
		if (k == 0)
		{
			cout << n / 2;
		}
		else
		{
			cout << n;
		}
	}
	else if (fb)
	{
		int cnt = 0;
		
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 1)
			{
				cnt++;
			}
		}
		
		if (k == 0)
		{
			cout << cnt / 2;
		}
		else if (k == 1)
		{
			cout << cnt;
		}
	}
	else if (n <= 3000)
	{
		for (int i = 1; i <= n; i++)
		{
			long long tmp = a[i];
			s[i][i] = tmp;
			
			for (int j = i + 1; j <= n; j++)
			{
				tmp = tmp ^ a[j];
				s[i][j] = tmp;
			}
		}
		
		int ans = 0, st = 1;
		
		for (int p = 1; p <= n; p++)
		{
			for (int i = st; i <= p; i++)
			{
				if (s[i][p] == k)
				{
					st = p + 1;
					ans++;
					break;
				}
			}
		}
		
		cout << ans;
	}
	
	return 0;
}

