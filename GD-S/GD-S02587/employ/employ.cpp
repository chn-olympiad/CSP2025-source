#include <bits/stdc++.h>
using namespace std;

const int Mod = 998244353;
int c[1005], t[1005], id[1005], vis[1005], n, m;
long long res;

void dfs(int pos, int pas, int cnt)
{
	if (pos > n)
	{
		if (pas >= m)
		{
			res++;
			res %= Mod;
		}
		
		return;
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			
			if (t[pos] == 0 || cnt >= c[i])
			{
				dfs(pos + 1, pas, cnt + 1);
			}
			else
			{
				dfs(pos + 1, pas + 1, cnt);
			}
			
			vis[i] = false;
		}
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	string s;
	cin >> n >> m >> s;
	
	for (int i = 1; i <= n; i++)
	{
		t[i] = s[i - 1] - '0';
		cin >> c[i];
	}
	
	if (n <= 20)
	{
		dfs(1, 0, 0);
		cout << res;
	}
	else if (m == 1)
	{
		res = 1;
		
		for (int i = 1; i <= n; i++)
		{
			res = res % Mod * i % Mod;
		}
		
		cout << res;
	}
	
	return 0;
}

