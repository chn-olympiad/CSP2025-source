#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long ans;
bool pd()
{
	bool bo=true;
	for(int i=1;i<n;i++)
	{
		if(a[i]!=a[i+1])
		{
			bo=false;
			break;
		}
	}
	return bo;
}
long long jk(int k)
{
	long long sum=1;
	for(int i=2;i<=k;i++)
	{
		sum*=i;
		sum%=998244353;
	}
	return sum;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3 && a[1]+a[2]>a[3])
	{
		cout<<1;
		return 0;
	}else if(n==3 && a[1]+a[2]<=a[3])
	{
		cout<<0;
		return 0;
	}
	if(pd())
	{
		for(int i=3;i<=n;i++)
		{
			ans+=jk(n)/(jk(i)*jk(n-i));
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	cout<<n;
	return 0;
}