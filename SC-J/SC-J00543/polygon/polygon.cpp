#include <bits/stdc++.h>
using namespace std;
long long n,a[5010],maxa,sum[5010],cnt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(maxa==1)
	{
		sum[1]=n;
		for(long long i=2;i<=n;i++)
		{
			sum[i]=(sum[i-1]*(n-i+1)/i)%998244353;
			if(i>=3)cnt=(cnt+sum[i])%998244353;
		}
		cout<<cnt;
	}
	else
	{
		for(long long i=1;i<=(2<<(n-1));i++)
		{
			long long num=i,t=0,m=0;
			for(long long j=1;num!=0;j++)
			{
				if(num%2==1)
				{
					t+=a[j];
					m=max(m,a[j]);
				}
				num/=2;
			}
			if(t>2*m)cnt++;
		}
		cout<<cnt;
	}
	return 0;
}