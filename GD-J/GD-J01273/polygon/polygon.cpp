#include<bits/stdc++.h>
using namespace std;
long long n,f[2][5005],mod=998244353,ans;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	f[1][0]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=5001;j++)
			f[i&1][j]=0;
		for(int j=0;j<=5001;j++)
		{
			f[i&1][j]=(f[i&1][j]+f[(i-1)&1][j])%mod;
			f[i&1][min(j+a[i-1],5001)]=(f[i&1][min(j+a[i-1],5001)]+f[(i-1)&1][j])%mod;		
		}
		if(i>=3)
		{
			for(int j=a[i]+1;j<=5001;j++)
			{
				ans=(ans+f[i&1][j])%mod;
			}
		}
	}	
	cout<<ans;
}
