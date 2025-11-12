#include <bits/stdc++.h>
#define int long long
using namespace std;
int in(){
	int w = 0 , f = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f = -1;
		ch = getchar();
	}
	while('0'<=ch&&ch<='9'){
		w = (w<<3)+(w<<1)+(ch&15);
		ch = getchar();
	}
	return w*f;
}
const int N = 5015 , mod = 998244353;
int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
int n,dp[N],a[N],ans;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n = in();
	for(int i = 1 ; i<=n ; i++) a[i] = in();
	sort(a+1,a+n+1);
	dp[0] = 1;
	long long ans = 0;
	for(int i = 1 ; i<n ; i++){
		dp[5001] = dp[5001]*2%mod;
		for(int j = 5001 - a[i] ; j<=5000 ; j++)
			dp[5001] = add(dp[5001],dp[j]);
		for(int j = 5000 ; j>=a[i] ; j--)
			dp[j] = add(dp[j],dp[j-a[i]]);
		for(int j = a[i+1]+1 ; j<=5001 ; j++)
			ans = add(ans,dp[j]);
	}
	printf("%lld",ans);
	return 0;
}