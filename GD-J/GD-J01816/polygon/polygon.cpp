#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long n,a[5100],f[5100][5100],p[5100],x,s;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<=a[n]+1;j++)
		{
			f[i][j]+=f[i-1][j];
			f[i][j]%=mod;
			x=min(a[n]+1,j+a[i]);
			f[i][x]+=f[i-1][j];
			f[i][x]%=mod;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=a[n]+1;j++)
		{
			f[i][j]+=f[i][j-1];
			f[i][j]%=mod;
		}
	}
	for(long long i=3;i<=n;i++)
	{
		s+=f[i-1][a[n]+1]-f[i-1][a[i]];
		s%=mod;
	}
	cout<<s;
	return 0;
}
