#include <bits/stdc++.h>
using namespace std;
int n,maxn,sum,ans;
int a[5005];
int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i + 1;j <= n;j++)
		{
			for (int k = j + 1;k <= n;k++)
			{
				sum = a[i] + a[j] + a[k];
				maxn = max(a[i],max(a[j],a[k]));
				if (sum > 2 * maxn)
				{
					ans ++;
				}
				for (int l = k + 1;l <= n;l++)
				{
					sum = a[i] + a[j] + a[k] + a[l];
					maxn = max(a[i],max(a[j],max(a[k],a[l])));
					if (sum > 2 * maxn)
					{
						ans ++;
					}
					for (int r = l + 1;r <= n;r++)
					{
						sum = a[i] + a[j] + a[k] + a[l] + a[r];
						maxn = max(a[i],max(a[j],max(a[k],max(a[l],a[r]))));
						if (sum > 2 * maxn)
						{
							ans ++;
						}
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
} 
