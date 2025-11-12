#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[5005],flag=0;
long long jc(int x)
{
	long long sum=1;
	for (int i=2;i<=x;i++)
	{
	    sum*=i;
	    sum%=998244353;
	}
	return sum;
}
long long plzh(int x,int y)
{
	return (jc(x)/(jc(y)*jc(x-y)%998244353))%998244353;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if (n==3)
	{
		flag=1;
		if (a[3]>=a[1]+a[2]) cout<<0;
		else cout<<1;
		return 0;
	}
	if (a[n]==1 && flag==0)
	{
		long long cnt=0;
		for (int i=3;i<=n;i++)
		{
		    cnt+=plzh(n,i);
		    cnt%=998244353;
		}
		cout<<cnt;
		return 0;
	}
}