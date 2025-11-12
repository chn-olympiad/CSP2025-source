#include<bits/stdc++.h>
using namespace std;
int n,m,sum[505],summ,c[505];
char s[505];
const long long MOD=998244353;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int l=1;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]!='1')
		{
			l=0;
			sum[i]=sum[i-1]+1;
		}
		else
		{
			sum[i]=sum[i-1];
		}
	}
	if(l==1)
	{
		int ans=1;
		for(int i=2;i<=n;i++)
		{
			ans=(ans*i)%MOD;
		}
		cout<<ans;
		return 0;
	}
	if(m==n)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]>sum[n])
		{
			summ++;
		}
	}
	if(summ>=m)
	{
		int ans=1;
		for(int i=2;i<=n;i++)
		{
			ans=(ans*i)%MOD;
		}
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		
	}
}
