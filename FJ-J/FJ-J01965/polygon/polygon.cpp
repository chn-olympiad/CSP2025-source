#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int n,a[5005],mx,f[5005],low[5005];
int l[5005],dp[5005],ans=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	mx=a[n],f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=mx;j>=a[i];j--)
			f[j]=(f[j]+f[j-a[i]])%mod;
	low[0]=0;
	for(int i=1;i<=mx;i++)
		low[i]=(low[i-1]+f[i])%mod;
	for(int i=n;i>=1;i--)
		if(a[i]!=a[i+1])
			low[a[i]]=(low[a[i]]-i+mod)%mod;
		else low[a[i]]=low[a[i+1]];
	l[0]=1;
	for(int i=1;i<=n;i++)
		l[i]=(l[i-1]*2)%mod;
	for(int i=3;i<=n;i++)
		dp[i]=(l[i-1]-i-low[a[i]]+2*mod)%mod;
	for(int i=3;i<=n;i++)
		ans=(ans+dp[i])%mod;
	cout<<ans;
	return 0;
}
