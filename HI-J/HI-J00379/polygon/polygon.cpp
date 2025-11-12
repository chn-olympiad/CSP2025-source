#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,a[5050],f[2010101],g[2010101],s[5050],ans;

signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[3]*2<a[3]+a[1]+a[2])puts("1");
			else puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=s[i];j>=a[i];j--)f[j]+=f[j-a[i]];
		for(int j=2*a[i]+1;j<=s[i];j++)ans=(ans+f[j])%998244353ll;
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
