#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005][3],dp[50005][3];
signed main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--){
		int n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		}
		for(int g=1;g<=3;g++){
			for(int len=1;len<=n/2;len++){
				for(int i=1;i<=n;i++){
					dp[len][g]=max(dp[len][g],dp[len-1][g]+a[i][g]);
//					cout<<dp[len][g]<<" "<<dp[len-1][g]<<" "<<a[i][g]<<"\n";
				}
			}
		}
		int ans=0;
		for(int len1=1;len1<=n/2;len1++){
			for(int len2=1;len2<=n-len1&&len2<=n/2;len2++){
				int len3=n-len1-len2;
				if(len3>n/2)continue;
//				printf("%lld %lld %lld %lld %lld %lld\n",len1,len2,len3,dp[len1][1],dp[len2][2],dp[len3][3]);
				ans=max(ans,dp[len1][1]+dp[len2][2]+dp[len3][3]);
			}
		}
		printf("%lld\n",ans);
		memset(a,sizeof a,0);
		memset(dp,sizeof dp,0);
	}
	return 0;
}

