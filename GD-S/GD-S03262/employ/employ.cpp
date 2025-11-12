#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],jc[505],ny[505],ans,dp[505][505];
bool a[505];
char cc;
const long long mod=998244353;
long long pw(long long x,long long y)
{
	if (y==1) return x;
	long long p=pw(x,y/2);
	if (y%2==0) return p*p%mod;
	return p*p%mod*x%mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cc=getchar();
		while (cc!='0'&&cc!='1') cc=getchar();
		a[i]=cc-'0';
	}
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	c[n+1]=n+1;
	jc[1]=1;ny[1]=1;
	for (int i=2;i<=n;i++)
	{
		jc[i]=jc[i-1]*i;
		jc[i]%=mod;
		ny[i]=pw(jc[i],mod-2);
	}
	if (m==1)
	{
		ans=jc[n];
		long long anss,r=0,r2=0,anss2=1;
		for (int i=1;i<=n;i++)
		{
			if (a[i]==false) r++;
			else
			{
				for (int j=1;j<=n;j++)
				{
					if (c[j]<i&&c[j+1]>=i)
					{
						anss2*=(j-r2);
						anss2%=mod;
						break;
					}
				}
				r2++;
				if (c[r2]>=i)
				{
					break;
				}
			}
		}
		anss=(jc[n]-(jc[r]%mod*anss2%mod)+mod)%mod;
		cout<<anss;
		return 0;
	}
	if (m==n)
	{
		for (int i=1;i<=n;i++)
		{
			if (c[i]==0||a[i]==false)
			{
				cout<<0;
				return 0;
			}
		}
		cout<<jc[n];
		return 0;
	}
	return 0;
}
