//polygon
#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,a[5010];
int dp[5010]={1},cnt;
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans=(ans+cnt)%M;
		cnt=cnt*2%M;
		for(int j=a[n];j>a[n]-a[i];j--) cnt=(cnt+dp[j])%M;
		for(int j=a[n];j>=a[i];j--){
			if(j!=a[i]) ans=(ans+dp[j])%M;
			dp[j]=(dp[j]+dp[j-a[i]])%M;
		}
	}
	printf("%lld",ans);
	return 0;
}
