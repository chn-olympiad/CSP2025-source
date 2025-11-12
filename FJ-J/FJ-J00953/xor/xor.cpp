#include <bits/stdc++.h>
using namespace std;
int n,k,a[500002],sum[500002],ans;
int main()
{
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	if (k<=1)
	{

		for(int l=1;l<=n;l++)
		{
			for(int r=l;r<=n;r++)
			{
				if ((sum[r]-sum[l-1]-r+l-1)==k) ans++;
			}
		}
		cout<<ans;
	}
	else if (k<=255)
	{
		for(int l=1;l<=n;l++)
		{
			for(int r=l;r<=n;r++)
			{
				int sum1=a[l];
				for(int i=l+1;i<=r;i++)
				{
					sum1=sum1&a[i];
				}
				if (sum1==k)
				{
					ans++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
