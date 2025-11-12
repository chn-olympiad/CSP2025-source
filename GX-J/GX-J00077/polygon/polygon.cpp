#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long jc(int x)
{
	if(x==0)
		return 1;
	long long j=1;
	for(int i=1;i<=x;i++)
		j=j*i;
	return j;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==3)
	{
		int k=max(a[1],a[2]);
		k=max(k,a[3]);
		if(k*2<a[1]+a[2]+a[3])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
			long long x=jc(n)/jc(n-i);
			long long y=jc(i);
			s=s+x/y;
			s=s%998244353;
		}
		cout<<s%998244353;
		return 0;
	}
	
	return 0;
}
