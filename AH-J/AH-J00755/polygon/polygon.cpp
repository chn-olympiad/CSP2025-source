#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],z[500005],f[500005],s,ans,mod=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],s+=a[i];
	s%=mod;
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i]+1;j<=s;j++)
			ans=(ans+f[j])%mod;
		for(int j=s;j>=a[i];j--)
			f[j]=(f[j]+f[j-a[i]])%mod;
	}
	cout<<ans;
	
	return 0;
}	
