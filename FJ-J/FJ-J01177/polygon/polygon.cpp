#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],sum[5010],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	if(n<3)
	{
		cout << 0;
		return 0;
	}
	cin >> a[1];
	for(int i=2;i<=n;i++)
	{
		cin >> a[i];
		sum[i]=a[i]+sum[i-1];
	}
	sort(a+1,a+n+1); 
	for(int i=3;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			for(int k=1;k<j;k++)
			{
				if(sum[j]-sum[k]>a[i])
				{
					ans++;
					ans%=998244353;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
