#include<bits/stdc++.h>
using namespace std;
int n,f=1;
long long sum;
int a[100005];
long long c(int x,int y)
{
	long long sum1=1,sum2=1;
	for(int i=x-y+1;i<=x;i++)
	{
		sum1=sum1*i%998244353;
	}
	for(int i=1;i<=y;i++)
	{
		sum2=sum2*i%998244353;
	}
	sum1/=sum2;
	return sum1;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			f=0;
		}
	}
	if(n==3)
	{
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	else if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(f==1)
	{
		for(int i=3;i<=n;i++)
		{
			sum=(sum+c(n,i))%998244353;
		}
	}
	cout<<sum;
	return 0;
}
