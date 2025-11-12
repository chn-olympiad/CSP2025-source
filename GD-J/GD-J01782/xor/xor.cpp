#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int kkksc[500005];
int mapp[4194309];
int dp[500005];
int ans=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		kkksc[i]=(kkksc[i-1]^a[i]);
	}
	for(int i=0;i<=4194034;i++){
		mapp[i]=-1;
	}
	for(int i=1;i<=n;i++){
		int yys=(kkksc[i]^k);
		if(mapp[yys]!=-1) dp[i]=mapp[yys]+1;
		else{
			if(a[i]==k) dp[i]=dp[i-1]+1;
			else dp[i]=0;
		}
		dp[i]=max(dp[i-1],dp[i]);
		mapp[kkksc[i]]=max(mapp[kkksc[i]],dp[i]);
		ans=max(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}
