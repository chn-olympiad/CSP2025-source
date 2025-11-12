#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
ll n;
ll a[5010],sum[5010];
ll f[5010][5010];
int main()
{
	freopen("polygon.in","r","stdin");
	freopen("polygon.out","w","stdout");
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]=a[i];
		}
	}
	for(int g=1;g<=n-1;g++) 
	{
		for(int i=1;i<=n-g;i++)
		{
			f[i][i+g]=max(f[i][i+(g-1)],f[i+1][i+g]);
		}
	} 
	int ans=0;
	for(int i=n;i>=3;i--)
	{
		for(int j=1;j<=i-2;j++)
		{
			int cnt=sum[i]-sum[j-1];
			int maxx=f[i][j];
			if(maxx*2<cnt) ans++; 
		}
	}
	cout<<ans%mod;
	return 0;
}

