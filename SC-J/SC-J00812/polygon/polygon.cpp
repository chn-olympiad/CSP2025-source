#include<bits/stdc++.h>
using namespace std;
long long n,num,ans;
long long a[5005];
long long A(long long x,long long y)
{
	long long m=1;
	for(int i=0;i<y;i++)
	{
		m*=(x-i);
	}
	return m;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) num++;
	}
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++)
	{
		ans=(ans+A(n,i)/A(i,i))%998244353;
	}
	cout<<ans;
	return 0;
}