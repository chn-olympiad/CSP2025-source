#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD=998244353;
const int N=10010;
ll n,a[N],dp[N][2],w[N][2],ww[N][2],f[N],dp2[N][2],maxn,ans;
//dpi,j:考虑前i个数，总和>j的方案数
//dp2i,j:考虑前i个数，选第i个人，总和>j的方案数 
//wi,j:考虑前i个数，选择2个数，使得总和>j的方案数 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ll op=i&1;
		for(int j=0;j<=2*maxn;j++)
		{
			dp[j][op]=dp[j][op^1];
			w[j][op]=w[j][op^1];
			//if(j<a[i]) continue;
			dp2[j][op]=(dp[max(0ll,j-a[i])][op^1]+w[max(0ll,j-a[i])][op^1])%MOD;
			dp[j][op]=(dp[j][op]+dp[max(0ll,j-a[i])][op^1]+w[max(0ll,j-a[i])][op^1])%MOD;
			w[j][op]=(w[j][op]+ww[max(0ll,j-a[i])][op^1])%MOD;
		}
		for(int j=0;j<=2*maxn;j++)
		{
			ww[j][op]=ww[j][op^1];
			if(j<a[i]) ww[j][op]=(ww[j][op]+1)%MOD;
		}
		f[i]=dp2[2*a[i]][op];
	}
	for(int i=1;i<=n;i++) ans=(ans+f[i])%MOD;
	printf("%lld\n",ans);
	return 0;
}
