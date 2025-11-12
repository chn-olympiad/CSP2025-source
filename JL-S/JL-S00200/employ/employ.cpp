#include <iostream>
#define int long long

using namespace std;

const int N = 510, mod = 998244353;

int n, m, cnt;
string s;
int c[N], a[N];
bool st[N];

bool check()
{
	int cur = 0;
	for (int i = 0; i < n; i ++ )
	{
		if (cur >= c[a[i]]) cur ++ ;
		else if (s[i] == '0') cur ++ ;
	}
	return n - cur >= m;
}

void dfs(int u)
{
	if (u == n)
	{
		// for (int i = 0; i < n; i ++ )
		// 	cout << a[i] << ' ';
		// cout << endl;
		if (check()) cnt = (cnt + 1) % mod;
		return;
	}
	for (int i = 1; i <= n; i ++ )
	{
		if (!st[i])
		{
			st[i] = true, a[u] = i;
			dfs(u + 1);
			st[i] = false, a[u] = 0;
		}
	}
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i ++ )
		cin >> c[i];
	dfs(0);
	cout << cnt << endl;

	return 0;
}