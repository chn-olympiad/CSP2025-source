#include <bits/stdc++.h>

using namespace std;
long long n,a[5005],ans,ans1;
const long long mod=998244353;
bool flag=true;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=1){flag=false;}
	} 
	if(flag==true)
	{
		for(int i=3;i<=n;i++)
		{
			long long f=1,s=1;
			for(int j=n;j>=n-i+1;j--)
			{
				f*=j%mod;
			}
			for(int j=1;j<=i;j++)
			{
				s*=j%mod;
			}
			ans1+=(f/s)%mod;
		}
		cout<<ans1;
		return 0;
	}
	for(int i=0;i<(1<<n);i++)
	{
		long long maxx=0,sum=0,choose=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				maxx=max(maxx,a[j]);
				choose++;
			}
		}
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				sum+=a[j];
			}
		}
		if(maxx*2<sum&&choose>=3){ans++;ans%=mod;}
	}
	cout<<ans;
	return 0;
}

