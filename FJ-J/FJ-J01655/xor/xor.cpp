#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10; 
long long n,k;
long long a[N];
long long sum[N],dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sum[0]=0,sum[1]=a[1];
	for(long long i=2;i<=n;i++){
		sum[i]=(sum[i-1]^a[i]);
	}
	dp[0]=0,dp[1]=(sum[1]==k);
	for(long long i=2;i<=n;i++){
		dp[i]=(a[i]==k);
		for(long long j=i;j>=max(i-(1<<9),(long long)1);j--){
			dp[i]=max(dp[i],dp[j-1]+((sum[i]^sum[j-1])==k));
		}
	}
	cout<<dp[n];
	return 0;
}
