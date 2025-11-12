#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,a[5005],dp[20005],cnt,candybar;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i <= n;i++)scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++){
		for(int j = a[i]+1;j <= 20001;j++)cnt+=dp[j],cnt%=mod;
		dp[20001]*=2;dp[20001]%=mod;for(int j = 20000;j>=0;j--)dp[min(20001ll,j+a[i])]+=dp[j],dp[min(20001ll,j+a[i])]%=mod;
		dp[a[i]]++,dp[a[i]]%=mod;
	}
	cnt%=mod;
	printf("%lld\n",cnt);
	return 0;
}
