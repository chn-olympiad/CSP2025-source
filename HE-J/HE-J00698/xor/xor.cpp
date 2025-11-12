#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, k, a[500010], sum;

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if (a[i] == 1)
		{
			sum ++;
		}
	}
	if (k == 1)
	{
		if (sum % 2 != 0 || sum == (n - sum))
		{
			cout << n - (n - sum);
		}
		else cout << "0";
	}	
	if (k == 0)
	{
		if (n % 2 == 0)
		{
			cout << n / 2;		
		}
		else
		{
			cout << "0";
		}
	}
	return 0;
}
