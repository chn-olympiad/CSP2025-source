#include <bits/stdc++.h>

using namespace std;

int n, k, f;
int a[500010];
int x, maxn = -1;
int sum;
int c[500010];


int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if(i == 1) x = a[i];
		else if(x != a[i])
		{
			f = 1;
		}
		maxn = max(maxn, a[i]);
		c[i] = c[i - 1] ^ a[i];
	}
	if(k == 0 && f == 0 && x == 1)
	{
		cout << n / 2 << '\n';
		return 0;
	}
	if(maxn <= 1 && k <= 1)
	{
		if(k == 0)
		{
			for(int i = 1; i <= n; i ++)
			{
				if(a[i] == 1 && a[i + 1] == 1)
				{
					i ++;
					sum ++;
				}
				if(a[i] == 0)
				{
					sum ++;
				}
			}
			cout << sum << '\n';	
		}
		else
		{
			for(int i = 1; i <= n; i ++)
			{
				if(a[i] == 1)
				{
					sum ++;
				}
			}
			cout << sum << '\n';
		}
		return 0;
	}
	int now = 1;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = now; j <= i; j ++)
		{
			if((c[i] ^ c[j - 1]) == k)
			{
				sum ++;
				now = i + 1;
				break;
			}
		}
	}
	cout << sum << '\n';
	return 0;
}
