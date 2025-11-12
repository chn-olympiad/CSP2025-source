#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e3+10,mod=998244353;
int a[N];
LL dp[N*N]; 
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	memset(dp,0,sizeof(dp));
	dp[a[1]]=1; 
	dp[0]=1;
	LL ans=a[1]; 
	LL k=0;
	for(int i=2;i<=n;i++)
	{
		ans+=a[i];
		for(int j=ans;j>=a[i];j--)
		{
			dp[j]=(dp[j-a[i]]+dp[j])%mod;
			if(j-a[i]>=a[i]+1)
			{
				k=(k+dp[j-a[i]])%mod;
			}
		}
	}
	printf("%lld\n",k);
	return 0;
}
