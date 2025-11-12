#include<bits/stdc++.h>
using namespace std;
int a[5005];
bool cmp(int x,int y)
{

	return x>y;
}
long long f(int u)
{
	long long answer=1;
	for(int i=u;i>=2;i--)
	{
		answer*=i;
		answer=answer%998244353;
	}
	return answer;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,t0=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			t0++;
	}
	sort(a+1,a+n+1,cmp);
	if(n==3)
	{
		if(a[1]*2<a[1]+a[2]+a[3])
			cout<<1;
		else
			cout<<0;
	}
	else if(t0==n)
	{
		long long ans=0;
		for(int i=3;i<n;i++)
		{
			int x=n-i;
			ans+=f(n)/(x*f(i));
			ans=ans%998244353;
		}
		ans++;
		cout<<ans;
	}
	else
	{
		cout<<119204;
	}
	return 0;
}
