#include<bits/stdc++.h>
using namespace std;
int n,a[5005],t;
long long sum=0,ans=1;
int main()
{
	a[0]=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		t=0;
		ans=1;
		for(int j=1;j<i;j++)
		{
			if((a[i]-a[j])<=((a[i]-a[i-1])*2))
			{
				t=j-1;
				break;
			}
		}
		for(int j=1;j<=t;j++)
		{
			ans=ans*2%998244353;
		}
		if(t!=0)
		{
		sum=(sum+ans)%998244353;			
		}
	}
	cout<<sum+2;
	return 0;
}
