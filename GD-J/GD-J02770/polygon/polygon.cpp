#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long mod=998244353;
ll n,a[5005],dp[5005];//dp[i] 表示 到达长度i的情况 
ll sum,minx,maxx,ans,r[50005];
int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
scanf("%lld",&n);
for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
sort(a+1,a+n+1);
dp[a[1]+a[2]]++;
dp[a[1]]++;
dp[a[2]]++; 
maxx=minx=a[1]+a[2];
for(int i=3;i<=n;i++)	
{
	for(int j=maxx;j>=minx;j--)
		if(j>a[i]) ans=(ans+dp[j])%mod;
	for(int j=maxx;j>=a[1];j--)
		dp[j]=(dp[j-a[i]]+dp[j])%mod;
	maxx=maxx+a[i];	
}
printf("%lld",ans);
fclose(stdin);
fclose(stdout);
	return 0;
}
