#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int md = 998244353;
int n,a[50005],dp[100005],qp[100005],f[10005],ans = 0;
int qpow(int a,int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = (res * a) % md;
		a = a * a % md;
		b >>= 1;
	}
	return res;
	
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	qp[0] = 1;
	for (int i = 1;i <= n;i++) qp[i] = qp[i - 1] * 2 % md;
	dp[0] = 1;
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
	{
		int now = 0;
		for (int j = 10000;j >= a[i];j--)
		{
			dp[j] = (dp[j] + dp[j - a[i]]) % md;
			if (dp[j - a[i]] && j <= 2 * a[i]) now = (now + dp[j - a[i]]) % md;
		}
		int tot = (qp[i - 1] - now + md) % md; 
		ans = (ans + tot) % md;
	//	cout<<ans<<'\n';
	}
	cout << ans << '\n';
	return 0;
}
