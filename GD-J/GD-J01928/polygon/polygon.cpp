#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=5100;
const ll MOD=998244353;
int n,a[N];
ll dp[N]={1},ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=5001;j>=0;j--) dp[j]=(dp[max(j-a[i],0)]+dp[j])%MOD;
		/*printf("%d\n",i);
		for(int j=1;j<=6;j++) printf("%lld ",dp[j]);
		printf("\n");*/
		if(i>=2&&i<n) 
		{
			ans=(ans+dp[a[i+1]+1])%MOD;
			//printf("%d %lld\n",i,dp[a[i+1]+1]);
		}
	}
	printf("%lld",ans);
	return 0;
}
