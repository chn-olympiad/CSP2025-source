#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long ans;
int mod=998244353;
long long ksm(long long a,long long b)
{
	int t=1;
	while(b)
	{
		if(b&1)
		{
			t=(t*a%mod);
		}
		a=(a*a%mod);
		b>>=1;
	}
	return t;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=1)
		f=0;
	}
	if(f==1)
	{
		ans=ksm(2,n)%mod-1-n-n*(n-1)/2;
	}
	else
	{
		sort(a+1,a+n+1);
		if(n<=3)
		{
			if(a[1]+a[2]<=a[3])
			{
				ans=0;
			}
			else
			{
				ans=1;
			}
		}
		
	}
	cout<<ans%mod;
	return 0;
}
