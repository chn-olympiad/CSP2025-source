#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=5e3+5;
const long long MOD=998244353; 

int n,MAX;

int a[MAXN];

long long ans;

long long dp[MAXN<<1];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		MAX=max(MAX,(a[i]<<1));
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	for (int i=1;i<=n;i++){
		for (int j=a[i]+1;j<=MAX+1;j++){
			ans=(ans+dp[j])%MOD;
		}
		for (int j=MAX+1;j>=MAX-a[i]+1;j--){
			dp[MAX+1]=(dp[MAX+1]+dp[j])%MOD;
		}
		for (int j=MAX;j>=a[i];j--){
			dp[j]=(dp[j]+dp[j-a[i]])%MOD;
		}
	}
	printf("%lld",ans);
	return 0;
}
