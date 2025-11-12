#include <bits/stdc++.h>
using namespace std;
long long M=998244353;
long long n,a[5005],b[5005],c[5005];
bool f=true;
long long C(int n,int m)
{
	long long ans=1;
	for (int i=1;i<=n;i++)
	{
		ans*=i%M;
	}
	for (int i=1;i<=m;i++)
	{
		ans/=i;
	}
	return ans;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]!=1)
		{
			f=false;
		}
	}
	sort(a+1,a+n+1);
	if (n<=3)
	{
		if (a[1]+a[2]+a[3]>a[3]*2)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else if (f)
	{
		long long sum=0;
		for (int i=3;i<=n;i++)
		{
			sum+=(C(n,i)%M);
			sum%=M;
		}
		cout<<sum;
	}
	else
	{
		cout<<6;
	}
	return 0;
}
