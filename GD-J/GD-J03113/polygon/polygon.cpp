#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long a[500005],b[500005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,i,j,k;
	cin >> n;
	for (i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (i=1;i<=n;i++)
	{
		b[i]=a[i]+b[i-1];
	}
	int maxx=-1,maxx1=-1;
	long long ans=0;
	for (i=n;i>=3;i--)
	{
		maxx=a[i];
		maxx1=2*a[i];
		for (j=i-1;j>=2;j--)
		{
			maxx-=a[j];
			for (k=1;k<=j-1;k++)
			{
				if (maxx<a[k])
				{
					ans=(ans+j-k)%998244353;
					break; 
				}
			}
			for (k=j-1;k>=1;k--)
			{
				if (a[i]+(b[j]-b[k-1])>maxx1)
				{
					ans=(ans+1)%9982434353; 
				}
			}
			maxx=a[i];
		}
	}
	cout << ans;
	return 0;
} 
