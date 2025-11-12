#include <bits/stdc++.h>
using namespace std;

int n,sum = 0,cnt = 0;
int a[5005];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=1;i<=n;i++)
	{
		int sum = a[i],maxn = a[i];
		for (int j=3;j<=n;j++)
		{
			for (int l=1;l<=n;l++)
			{
				for (int k=i+1;k<=n;k++)
				{
					sum += a[k];
					maxn = max(maxn,a[k]);
					if (sum > maxn * 2)
					{
						cnt++;
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;
}