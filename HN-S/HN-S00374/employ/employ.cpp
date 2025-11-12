#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int N = 505;
int n, m, c[N], diff, box[N], ans;
bool vis[N];
string s;
bool check()
{
	int cnt = 0, cnt2 = 0, si = 1;
	for (int i = 1; i + si <= n; i++)
	{
		while (c[box[i + si]] <= cnt && si + i <= n)
			si++, cnt++;
		if (s[box[si + i]] == '0')
			cnt++;
		else cnt2++;
		if (cnt > diff) return 0;
		if (cnt2 >= m) return 1;
	}
	return cnt2 >= m && cnt <= diff;
}
void dfs(int i)
{
	if (i > n)
	{
		if(check())
			ans++;
		ans %= mod;
		return ;
	}
	for (int j = 1; j <= n; j++)
	{
		if (!vis[j])
		{
			vis[j] = 1;
			box[i] = j;
			dfs(i + 1);
			vis[j] = 0;
		}
	}
	return ;
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	diff = n - m;
	s = '#' + s;
	int sum = 0;
	for (int i = 1; i <= n; i++)
		if (s[i] == '0')
			sum++;
	if (sum > m)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	dfs(1);
	cout << ans;
	return 0;
}

