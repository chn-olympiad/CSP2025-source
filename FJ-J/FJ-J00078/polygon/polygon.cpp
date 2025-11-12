#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
int pw[N];
int mod=998244353;
int f[N],g[N];
int a[N];
int n;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	pw[0]=1;
	for (int i=1;i<=5001;i++)
	{
		pw[i]=(pw[i-1]*2)%mod;
	}
	scanf("%lld",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	g[0]=1;
	for (int i=1;i<=n;i++)
	{
		int cnt=0;
		for (int j=0;j<=a[i];j++)
		{
			cnt+=g[j];
			cnt%=mod;
		}
		f[i]=(pw[i-1]-cnt)%mod;
		for (int j=5001;j>=a[i];j--)
		{
			g[j]+=g[j-a[i]];
		}
		
	}
	
	int ans=0;
	for (int i=3;i<=n;i++)
	{
		ans+=f[i];
		ans%=mod;
	}
	ans+=mod;
	ans%=mod;
	printf("%lld",ans);
	return 0;
}

