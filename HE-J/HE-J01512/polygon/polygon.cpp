#include<bits/stdc++.h>
using namespace std;
const long long MX=10000,INF=0x3f3f3f3f;
const long long MO=998244353;
long long a[MX];
long long dp[2501000],las[2501000];
void solve(){
	long long n;scanf("%lld",&n);
	for(long long i=1;i<=n;i++)  scanf("%lld",&a[i]),a[i]=-a[i];
	sort(a+1,a+1+n);
	long long ans=0,sum=0;
	for(long long i=1;i<=n;i++)  a[i]=-a[i],sum+=a[i];
	dp[a[1]]=1;
	for(long long i=1+1;i<=n;i++){
		for(long long k=sum;k>=a[i];k--){
			dp[k]+=dp[k-a[i]];
			dp[k]%=MO;
		}
	}
	for(long long k=a[1]*2+1;k<=sum;k++)  ans+=dp[k],ans%=MO;
//	for(long long i=0;i<=sum;i++)  printf("%lld ",dp[i]);printf("\n");
	for(long long i=0;i<=sum;i++)  las[i]=dp[i],dp[i]=0;
	for(long long j=2;j<=n;j++){
		sum-=a[j-1];
		for(long long i=0;i<=sum;i++)  dp[i]=las[i+a[j-1]-a[j]];
		for(long long i=a[j]*2;i<=sum;i++)  dp[i]-=dp[i-a[j]],dp[i]%=MO;
//		for(long long i=0;i<=sum;i++)  printf("%lld ",dp[i]);printf("\n");
		for(long long k=a[j]*2+1;k<=sum;k++)  ans+=dp[k],ans%=MO;
		for(long long i=0;i<=sum;i++)  las[i]=dp[i],dp[i]=0;
	}
	printf("%lld",((ans%MO)+MO)%MO);
    return ;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long T=1;
    while(T--)  solve();
    return 0;
}
/*
0 0 0 0 0 0 0 0 0 0 1 1 1 2 2 3 4 5 6 8 9 10 12 13 15 17 18 19 21 21 22 23 23 23 23 22 21 21 19 18 17 15 13 12 10 9 8 6 5 4 3 2 2 1 1 1 
0 0 0 0 0 0 0 0 0 1 1 1 2 2 3 4 5 6 7 8 9 10 11 12 13 13 13 14 13 13 13 12 11 10 9 8 7 6 5 4 3 2 2 1 1 1 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 1 1 1 2 2 3 4 5 5 6 7 7 8 8 8 8 8 7 7 6 5 5 4 3 2 2 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 1 1 2 2 3 4 4 4 5 5 5 5 4 4 4 3 2 2 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 1 1 1 2 2 3 3 3 3 3 3 2 2 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 1 1 1 2 2 2 2 2 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 0 1 1 1 2 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 0 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
872
*/
