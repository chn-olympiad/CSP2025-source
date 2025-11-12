#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
long long n,k;
long long a[500005];
long long sum[500005];
long long dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=(sum[i-1]^a[i]);
	}
	if(a[1]==k)	dp[1]=1;
	for(int i=2;i<=n;i++){
		for(int j=i;j>=1;j--){
			dp[i]=max(dp[i],dp[j]);
			if((sum[i]^sum[j-1])==k){
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}
	}
	printf("%lld\n",dp[n]);
	return 0;
}
//4 2 
//2 1 0 3
//2

//4 3 
//2 1 0 3
//2

//4 0 
//2 1 0 3
//1

//100 1 
//1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1
//63


