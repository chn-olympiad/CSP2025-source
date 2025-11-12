#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		s[i]=(s[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+(a[i]==k);
		for(int j=i-2;j>=0;j--){
			if(dp[j]<dp[i]-1){
				break;
			}
			if((s[i]^s[j])==k){
				dp[i]=max(dp[i],dp[j]+1);
				break;
			}
		}
	}
	printf("%d",dp[n]);
	return 0;
}
