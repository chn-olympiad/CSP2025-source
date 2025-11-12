#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 1;
int n, m, ans = 0, s[N], c[N], f[N];
void dfs(int x, int y)
{
	if(x > n && n - y >= m)
	{
		ans++;
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!f[i])
		{
			f[i] = 1;
			if(s[x] && c[i] > y)
			{
				dfs(x + 1, y);
			}
			else
			{
				dfs(x + 1, y + 1);
			}
			f[i] = 0;
		}
	}
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	//bool ff = 1;
	for(int i = 1; i <= n; i++)
	{
		char C;
		cin >> C;
		if(C == '1')
		{
			s[i] = 1;
		}
		/*else
		{
			ff = 0;
		}*/
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	dfs(1, 0);
	cout << ans;
}
