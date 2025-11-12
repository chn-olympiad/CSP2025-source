#include<iostream>
#include<algorithm>
using namespace std;
long long dp[25000005],ans;
int a[5005],n,sum;
const long long mod=998244353;
int main()
{
//freopen("polygon.in","r",stdin);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=sum;j>a[i];j--)
			ans=(ans+dp[j])%mod;
		sum+=a[i];
		for(int j=sum;j>=a[i];j--)
			dp[j]=(dp[j]+dp[j-a[i]])%mod;
	}
	printf("%lld",ans);
	return 0;
}
/*
luogu uid:759152
380pts
T4 spare no effort but still 80pts
how T4???
touch fish touch fish touch fish touch fish touch fish touch fish
I love zxy
Next year If I can go to DT and continue OI,I will biaobai
*/ 
