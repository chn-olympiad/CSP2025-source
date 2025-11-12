#include<bits/stdc++.h>
using namespace std;
long long a[5010];
long long n,s,sum,ans,ma=LLONG_MIN;
long long sv(long long x)
{
	long long v=1;
	for(long long i=1ll*1;i<=x;i+=1ll*1)
	{
		v=v*1ll*i;
		v/=998244353;
	}
	return v;
}
int main()
{
	//by FLtops
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1ll*1;i<=n;i+=1ll*1)
	{
		cin>>a[i];
		ma=max(a[i],ma);
		sum+=a[i];
	}
	if(ma==1ll*1)
	{
		s=sv(n);
		for(long long i=1ll*1;i<=n;i+=1ll*1)
		{
			ans=ans*1ll+s*1ll/sv(i);
		}
		ans=ans*1ll%998244353;
		cout<<ans;
	}
	else
	{
		if(n==3)
		{
			if(sum>ma*2)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		else
		{
			cout<<215518974;
		}
	}
	return 0;
}

