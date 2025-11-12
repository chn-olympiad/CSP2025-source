#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,a[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)flag=false;
	}
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[3]<a[1]+a[2])cout<<1;
		else cout<<0;
		return 0;
	}
	if(flag)
	{
		int ans=998244352;
		ans-=n;
		ans-=n*(n-1)/2;
		int ans2=1;
		for(int i=1;i<=n;i++)
		{
			ans2*=2;
			ans2%=mod;
		}
		ans+=ans2;
		ans%=mod;
		cout<<ans;
		return 0;
	}
	if(n<=20)
	{
		int ans=0;
		for(int i=1;i<(1<<n);i++)
		{
			int tmp1=0;tmp2=0;
			for(int j=0;j<n;j++)
			{
				if(i&(1<<j))
				{
					tmp2=j;
					tmp1+=a[i];
				}
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n-1;i++)
	{
		while(pq.size())
		{
			
			pq.pop();
		}
	}
	return 0;
}
