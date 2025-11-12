#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,a[5009];
long long dp[5009],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);dp[0]=1;
	for(int i=1;i<=n;i++){
		long long res=0;
		for(int j=a[i]+1;j<=5000;j++)res=(res+dp[j])%P;
		ans=(ans+res)%P;
		for(int j=5000;j>=0;j--)dp[min(j+a[i],5000)]=(dp[min(j+a[i],5000)]+dp[j])%P;
	}
	printf("%lld\n",ans);
}