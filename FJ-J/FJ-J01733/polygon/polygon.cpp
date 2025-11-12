#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int C(int a,int b)
{
	int x=1; 
	for(int i=a;i>=a-b+1;i--)
	{
		x*=i;
		x%=998244353; 
	}
	for(int i=1;i<=b;i++)x/=i;
	return x;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,f=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)f=0;
	}
	sort(a+1,a+1+n);
	if(n==3)
	{
		if((a[1]+a[2]+a[3])>2*a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	if(f)
	{
		int ans=0;
		for(int i=3;i<=n;i++)
		{
			ans+=(C(n,i))%998244353;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
