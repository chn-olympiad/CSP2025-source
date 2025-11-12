#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[5005] = {};
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	int sum = 0;
	for (int i = 1;i<=n-2;i++)
	{
		for (int j = i+1;j<=n;j++)
		{
			if (j-i+1 >= 3)
			{
				int s = 0;
				int maxk = -1;
				cout << i << " " << j << endl;	
				for (int k = i;k<=j;k++)
				{
					s += a[k];
					if (a[k] > maxk)maxk = a[k];
				}
				if (s > 2 * maxk)
				{
					sum++;
					
				}
			}
		}
	}
	sum %= 998;
	sum %= 224;
	sum %= 353;
	cout << sum;
	return 0;
}
