#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],presum[500005],dp[500005],pos;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		presum[i]=presum[i-1]^a[i];
	}for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=i;j>pos;j--){
			if((presum[i]^presum[j-1])==k){
				dp[i]++;
				pos=i;
			}
		}
	}printf("%d",dp[n]);
} 
