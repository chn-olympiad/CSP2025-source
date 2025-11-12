#include<bits/stdc++.h>
using namespace std;
long long a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3)
	{
		cout<<"0";
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>a[3]*2)
		cout<<"1";
		else
		cout<<"0";
		return 0;
	}
	if(a[1]==a[n]==1)
	{
		long long ans=0;
		for(int i=4;i<=n;i++)
		{
			long long sum=1;
			for(int j=i;j<=n;j++)
			{
				sum*=i;		
				sum%=998244353;
			}
			ans+=sum;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	long long sum=1;
	for(int i=1;i<=n-3;i++)
	{
		for(int j=4;j<=n;j++)
		{
			sum*=j;
			sum%=998244353;
		}
	}
	cout<<sum;
	return 0;
}
