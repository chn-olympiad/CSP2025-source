#include <bits/stdc++.h>
using namespace std;
const int N=5010;
const long long MOD=998244353;
int a[N];
long long dp[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,top=0;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		//dp[a[n]*2+1]=(dp[a[n]*2+1]*2)%MOD;
		//printf("!%lld\n",dp[a[n]*2+1]);
		for(int j=a[i]+1;j<=top;j++)ans=(ans+dp[j])%MOD;
		for(int j=top;j>=0;j--){
			if(dp[j]){
				int k=j+a[i];
				if(k>a[n]*2)dp[a[n]*2+1]=(dp[a[n]*2+1]+dp[j])%MOD,top=a[n]*2+1;
				else dp[k]=(dp[k]+dp[j])%MOD,top=max(top,k);
			}
		}
		dp[a[i]]=(dp[a[i]]+1)%MOD,top=max(top,a[i]);
		//for(int i=0;i<=top;i++)printf("%lld\n",dp[i]);
		//printf("\n");
	}
	printf("%lld",ans);
	return 0;
}
