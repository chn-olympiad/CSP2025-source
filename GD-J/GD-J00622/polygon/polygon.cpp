#include<cstdio>
#include<algorithm>
using namespace std;
const long long mod=998244353;
int n,a[5005],mx;
long long ans,dp[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(a[i],mx);
	}
	if(mx==1){
		ans=1;
		for(int i=1;i<=n;i++)(ans*=2)%=mod;
		(ans+=-1-n-n*(n-1)/2)%=mod;
		(ans+=mod)%=mod;
		printf("%lld",ans);
		return 0;
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=10001;j++)(ans+=dp[j])%=mod;
	    for(int j=10001;j>=0;j--)if(dp[j])
		    (dp[min(10001,j+a[i])]+=dp[j])%=mod;
		//for(int j=0;j<=15;j++)printf("%lld ",dp[j]);
		//printf("\n");
	}
	printf("%lld",ans);
	return 0;
}
