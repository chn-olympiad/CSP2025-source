#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=998244353;
ll dp[5010],sum[5010],p[5010];
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	p[0]=1;
	for(int i=1;i<=n;i++)p[i]=p[i-1]*2%P;
	ll ans=0;
	dp[0]=1;
	for(int i=0;i<=5000;i++)sum[i]=1;
	for(int i=1;i<=n;i++){
		(ans+=(p[i-1]-sum[a[i]]+P)%P)%=P;
		for(int j=5000;j>=a[i];j--){
			(dp[j]+=dp[j-a[i]])%=P;
		}
		for(int j=a[i];j<=5000;j++){
			sum[j]=(sum[j-1]+dp[j])%P;
		}
	}
	printf("%lld",ans);
	return 0;
}
