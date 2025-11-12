#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[2000005],xo[2000005],f[3000005],dp[2000005];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) xo[i] = xo[i - 1] ^ a[i];
	memset(f,-0x3f,sizeof f);
	f[xo[0]] = 0;
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		dp[i] = max(dp[i - 1],f[xo[i] ^ k] + 1);
		f[xo[i]] = max(f[xo[i]],dp[i]);
		ans = max(ans,dp[i]);
	}
	cout << ans << '\n';
	return 0;
}
