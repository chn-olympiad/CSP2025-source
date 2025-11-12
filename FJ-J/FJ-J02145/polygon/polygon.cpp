#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1])
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if(n==4)
	{
		int ans=0;
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3])
			ans++;
		if(a[1]+a[2]>a[4])
			ans++;
		if(a[1]+a[3]>a[4])
			ans++;
		if(a[2]+a[3]>a[4])
			ans++;;
		if(a[4]*2<a[1]+a[2]+a[3]+a[4])
			ans++;
		cout<<ans;
		return 0;
	}
	if(n>4)
	{
		sort(a+1,a+n+1);
		if(a[n]==1)
		{
			int ans=0;
			for(int i=3;i<=n;i++)
			{
				int tmp=n,cnt=n-1;
				for(int j=1;j<i;j++)
				{
					tmp*=cnt;
					cnt--;
				}
				int tmp1=i,cnt1=i-1;
				for(int j=1;j<=i;j++)
				{
					tmp1*=cnt1;
					cnt1--;
				}
				tmp=tmp/tmp1;
				ans+=tmp;
			}
			cout<<ans;
			return 0;
		}
		int sum=0,ans=0;
		for(int i=1;i<=n-2;i++)
		for(int j=i+2;j<=n;j++)
		{			
			sum+=a[j];
			if(sum>a[j]*2)
			{
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
