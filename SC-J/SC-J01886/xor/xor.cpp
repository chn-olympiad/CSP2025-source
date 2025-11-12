#include <bits/stdc++.h>
using namespace std;
int n, k, sum;
int a[500005];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int l=0, r=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			if (i==j&&a[i]==k)
			{
				if (i>=l&&i<=r)
				{
					l=i;
					r=i;
				}
				else if (i>r)
				{
					l=i;
					r=i;
					sum++;
				}
				continue;
			}
			int sum1, x, y;
			sum1=a[i];
			for (int g=i+1;g<=j;g++)
			{
				x=sum1&a[g];
				y=sum1|a[g];
				sum1=0;
				for (int h=0;h<=19;h++)
				{
					if (x&(1<<h) != y&(1<<h))
					{
						sum1+=(1<<h);
					}
				}
			}
			if (sum1==k)
			{
				if (i>r)
				{
					l=i;
					r=j;
					sum++;
				}
				else if (i>=l&&i<=r)
				{
					l=i;
					r=j;
				}
			}
		}
	}
	cout << sum;
	return 0;
}