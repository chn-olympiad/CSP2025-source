#include<bits/stdc++.h>
using namespace std;
long long popcount(long long x)
{
	if(x==1LL)return 1LL;
	return (x&1)+=popcount(x>>1);
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	char s[501];
	long long c[501],minimum1=LLONG_MAX,minimum2=LLONG_MIN,sums=0,t[500],top=-1;
	bool flag=true;
	for(long long i=1;i<=n;i++)
	{
		s[i]=getchar();
		if(s[i]=='0')flag=false;
		if(s[i]=='1')
		{
			minimum1=min(i,minimum1);
			sums++;
			t[++top]=i;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>c[i];
		minimum2=max(minimum2,c[i]);
	}
	if(flag)
	{
		long long ans=1LL;
		for(long long i=1LL;i<=n;i++)
		{
			ans*=i;
			ans%=998244353LL;
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		cout<<0;
		return 0;
	}
	if(n<=12)
	{
		long long a[13],ans=0;
		for(long long i=1;i<=n;i++)a[i]=i;
		while(next_permutation(a+1,a+n+1))
		{
			long long cnt1=0,cnt2=0;
			for(long long i=1;i<=n;i++)
			{
				if(s[i]=='0')
				{
					cnt1++;
				}
				else
				{
					if(cnt1>=c[i])
					{
						cnt1++;
					}
					else
					{
						cnt2++;
					}
				}
			}
			if(cnt2>=m)
			{
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(sums<=18)
	{
		long long ans=0;
		for(long long i=1;i<(1<<sums);i++)
		{
			if(popcount(i)<m)continue;
			for(long long j=0;j<sums;j++)
			{
				;
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
 } 
