#include <bits/stdc++.h>
using namespace std;
#define __MADE return 
#define IN 0
#define CHINA__ ;
#define int long long
#define filein(s) freopen(s, "r", stdin)
#define fileout(s) freopen(s, "w", stdout);
const int N = 1e5+5;
struct Node
{
	int a[3];
	int ch;
}g[N];
int n, dp[N];
bool cmp(Node A, Node B)
{
	if (A.a[0] == B.a[0])
	{
		if (A.a[1] == B.a[1]) return A.a[2] > B.a[2];
		return A.a[1] > B.a[1];
	}
	return A.a[0] > B.a[0];
}
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> g[i].a[0] >> g[i].a[1] >> g[i].a[2];
	}
	sort(g + 1, g + 1 + n, cmp);
	int x, y, z;
	x = y = z = 0;
	for (int i = 1; i <= n; i++)
	{
		if (g[i].a[1] + dp[i - 1] > g[i].a[0] + dp[i - 1] && y < n / 2 && g[i].a[1] > g[i].a[2]) dp[i] = dp[i - 1] + g[i].a[1], y++;
		else if (g[i].a[2] + dp[i - 1] > g[i].a[0] + dp[i - 1] && z < n / 2 && g[i].a[2] > g[i].a[1]) dp[i] = dp[i - 1] + g[i].a[2], z++;
		else
		{
			if (x == n / 2)
			{
				if (g[i].a[1] > g[i].a[2] && y < n / 2) dp[i] = dp[i - 1] + g[i].a[1], y++;
				else dp[i] = dp[i - 1] + g[i].a[2], z++;
			}
			else dp[i] = dp[i - 1] + g[i].a[0], x++;
		}
	}
	cout << dp[n] << endl;
	return ;
}
signed main()
{
	filein("club.in");
	fileout("club.out");
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--) solve();
	__MADE IN CHINA__
}
