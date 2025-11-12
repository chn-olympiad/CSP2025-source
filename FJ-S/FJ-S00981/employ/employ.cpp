#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[505],b[505][505],sum[505];
const int MOD=998244353;
string s;
int f(int x)
{
	if(x==1)
	{
		return 1;
	}
	else
	{
		return (f(x-1)*x)%MOD;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			sum[i+1]=sum[i]+1;
		}
		else
		{
			sum[i+1]=sum[i];
		}
	}
	if(sum[n]==0)
	{
		cout<<f(n)%MOD;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(sum[j]>=a[i]||s[j-1]=='0')
			{
				b[i][j]=0;
			}
			else
			{
				b[i][j]=1;
			}
//			cout<<b[i][j]<<" ";
		}
//		cout<<endl;
	}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		int now=0;
		for(int j=1;j<=n;j++)
		{
			if(b[i][j]==1)
			{
				now++;
			}
		}
		if(now!=0)
		{
			ans*=now;
		}
		ans%=MOD;
	}
	cout<<ans%MOD;
	return 0;
}
