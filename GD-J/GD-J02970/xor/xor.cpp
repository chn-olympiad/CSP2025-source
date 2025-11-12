#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define x first
#define y second

const int N = 5e5 + 5;
const LL INF = 0x7fffffffffffffff;

int n;
LL k;
LL a[N];

LL s[N];
LL maxdp[1 << 21];
LL dp[N], res;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	
	for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] ^ a[i];

	memset(dp, -0x7f, sizeof dp);
	memset(maxdp, -0x7f, sizeof maxdp);
	dp[0] = maxdp[0] = 0;
	for (int i = 1; i <= n; i ++ )
	{
		dp[i] = max(dp[i - 1], maxdp[s[i] ^ k] + 1);
		maxdp[s[i]] = max(maxdp[s[i]], dp[i]);
		
		res = max(res, dp[i]);
	}
	
	cout << res << '\n';
	
	return 0;
}

