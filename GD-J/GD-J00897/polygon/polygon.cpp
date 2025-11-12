#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 5010,mod = 998244353;
int a[maxn];
long long dp[maxn];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	dp[0] = 1;
	long long ans = 0,ok = 0;
	for(int i = 1;i <= n;i++){
		ans = (ans + ok) % mod;
		for(int j = 5000;j > a[i];j--)
			ans = (ans + dp[j]) % mod;
		ok = (ok << 1) % mod;
		for(int j = 5000 - a[i] + 1;j <= 5000;j++)
			ok += dp[j];
		for(int j = 5000;j >= a[i];j--)
			dp[j] = (dp[j] + dp[j-a[i]]) % mod;
	}
	printf("%lld",ans);
}
