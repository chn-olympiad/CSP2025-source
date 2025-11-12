#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 998244353;
int n, m, vis[505];
string s;
int c[505], qwq[505];
long long ans;
void dfs(int k, long long cnt, long long cnt2)
{
	if (k == n)
	{
		if (cnt >= m)
			ans++;
		ans %= MOD;
//		for (int i = 0; i < n; i++)
//			cout << qwq[i] << ' ';
//		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			qwq[k] = i;
			vis[i] = 1;
			if (s[k] == '0')
			{
				dfs(k + 1, cnt, cnt2 + 1);
			}
			else
			{
				if (cnt2 >= c[i])
					dfs(k + 1, cnt, cnt2 + 1);
				else if (s[k] == '1')
					dfs(k + 1, cnt + 1, cnt2);
			}
			vis[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	dfs(0, 0, 0);
	cout << ans << '\n';
	return 0;
}
