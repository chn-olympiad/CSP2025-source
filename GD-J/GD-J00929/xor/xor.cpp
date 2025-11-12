#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL maxn = 5e5 + 5;
LL n, a[maxn], sum[maxn], dp[maxn], k;
map <LL, LL> mp;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%lld %lld", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		sum[i] = (sum[i - 1] ^ a[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		if(mp[sum[i] ^ k] != 0 or (sum[i] ^ k) == 0) dp[i] = max(dp[i], dp[mp[sum[i] ^ k]] + 1);
		mp[sum[i]] = i;
	}
	printf("%lld", dp[n]);
	return 0;
}
