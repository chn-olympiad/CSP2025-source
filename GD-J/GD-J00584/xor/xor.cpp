#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],dp[500005],cnt[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cnt[i]=a[i]^cnt[i-1];
	}
	for(long long i=1;i<=n;i++){
		if(a[i]==k){
			dp[i]=max(dp[i],dp[i-1]+1);
		}else{
			for(long long j=i-1;j>0;j--){
				if(dp[j]+1<dp[i]){
					break;
				}
				if((cnt[i]^cnt[j-1])==k){
					dp[i]=max(dp[i],dp[j-1]+1);
					break;
				}
			}
		} 
		dp[i]=max(dp[i],dp[i-1]);
	}
	cout<<dp[n]<<endl;
}
