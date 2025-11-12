#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,a[5005],dp[5005][5005],res;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			for (int k=j+1;k<=n;k++)
			{
				for (int k=1;k<=i;k++)
				{
					int maxn,sum;
					maxn=a[k]>a[j]?a[k]:a[j]>a[i]?a[j]:a[i];
					sum=a[i]+a[j]+a[k];
					if (sum>maxn*2)
					{
						res++;
					}
				}
			}
		}
	}
	cout<<res;
	return 0;
}
