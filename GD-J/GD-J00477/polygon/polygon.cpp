#include <bits/stdc++.h>
using namespace std;
int n,sum[5001];
long long a[5001],f[25000001],ans;
int mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//思路：1.前缀和 2.排序 3.f[j]表示前i个数中前缀和为j的方案数
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	f[0]=1;
	for (int i=1;i<=n;i++)
	{
		for(int j=sum[i];j>=2*a[i]+1;j--)
		{
			f[j]=(f[j]+f[j-a[i]])%mod;
			ans=(ans+f[j-a[i]])%mod;
		}
		for (int j=2*a[i];j>=a[i];j--)  
		{
			f[j]=(f[j]+f[j-a[i]])%mod;
		}
	}
	cout<<ans;
	return 0;
}
