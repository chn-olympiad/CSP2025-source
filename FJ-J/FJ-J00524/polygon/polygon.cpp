#include<bits/stdc++.h>
#define mod 998244353
#define N 10005
using namespace std;
int n,m,ans,a[N],f[N],g[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	m=a[n]*2+1;
	f[0]=g[0]=1;
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		for(int j=a[i];j<m;j++) f[j]=g[j-a[i]];
		for(int j=m-a[i];j<=m;j++) f[m]=(f[m]+g[j])%mod;
		for(int j=0;j<=m;j++) g[j]=(g[j]+f[j])%mod;
		for(int j=a[i]*2+1;j<=m;j++) ans=(ans+f[j])%mod;
	}
	cout<<ans;
	return 0;
}
