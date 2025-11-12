#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
int n,k,a[500005];
ll dp[500005][3];
ll ans;
//0 idp 1 link 2 sum
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	int flag=1;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]!=1&&flag) flag=0;
	}
	if(flag){
		for(int len=2;len<=n;len+=2){
			ans+=n-len+1;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==k) dp[i][0]=1;
			if(dp[i-1][2]^a[i]==k){
				dp[i][1]=dp[i-1][1]+1;
				dp[i][2]=k;
			}else{
				if(a[i-1]^a[i]==k){
					dp[i][1]=dp[i-1][0]+1;
					dp[i][2]=k;
				}else{
					dp[i][2]=dp[i-1][2];
				}
			}
		}
		ans=dp[n][1];
		for(int i=n-1;i>=1;i--){
			if(dp[i][1]>dp[i+1][1]) ans+=dp[i][1];
		}
		ans*=2;
	}
	printf("%lld",ans);
	return 0;
}
