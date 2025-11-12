#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	unsigned long long ans=0;
	int n;
	cin>>n;
	int a[5010],b;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		a[i]=a[i]+a[i-1];
	}
	for(int i=n;i>0;i--)
	{
		for(int j=0;i-j>=3;j++)
		{
			if(a[i]-a[j]>2*(a[i]-a[i-1]))
			{
				ans=(ans+1)%998244353;
			}
		}
	}
	cout<<ans;
	return 0;
}
