#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 10;

int n, a[N][10];

ll f[N];
ll ans = 0;

inline void dfs (int i, int c1, int c2, int c3)
{
	if (i == n + 1)
	{
		ans = max(ans, f[i]);
		
		return;
	}
	
	if (c1 < n / 2)
	{
		f[i + 1] = f[i] + a[i][1];
		dfs(i + 1, c1 + 1, c2, c3);
	}
	if (c2 < n / 2)
	{
		f[i + 1] = f[i] + a[i][2];
		dfs(i + 1, c1, c2 + 1, c3);
	}
	if (c3 < n / 2)
	{
		f[i + 1] = f[i] + a[i][3];
		dfs(i + 1, c1, c2, c3 + 1);
	}
}

int T;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> T;
	
	while (T--)
	{
		ans = 0;
		
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		
		f[0] = 0;
		dfs(0, 0, 0, 0);
		
		cout << ans << endl;
	}
}
