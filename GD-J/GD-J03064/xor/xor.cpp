#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 10;
int sum[maxn],a[maxn],dp[maxn],n,k;
map<int,int> mp;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)cin >> a[i];
	mp[0] = 0;
	for(int i = 1;i <= n;i++)
	{
		sum[i] = sum[i - 1] ^ a[i];dp[i] = dp[i - 1];
		if(mp.count(sum[i] ^ k))dp[i] = max(dp[i],dp[mp[sum[i] ^ k]] + 1);
		mp[sum[i]] = i;
	}
	cout << dp[n] << '\n';
	return 0;
}
