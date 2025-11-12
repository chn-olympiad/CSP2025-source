#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 10, RP = LONG_LONG_MAX;

int n, k, a[N], ans	;
bool isa = true, v[N];

void dfs(int x, int sum)
{
	if (v[x])
		return ;
	if (sum == k)
	{
		ans++;
		return ;
	}
	for (int i = 1; i <= n; i++)
		if (!v[i] and i != x)
		{
			v[i] = true;
			dfs(i, sum xor a[i]);
		}
}

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != 1)
			isa = false;
	}
	if (k == 0 and isa)
		cout  << n / 2;
	else
	{
		for (int i = 1; i <= n; i++)
			if (!v[i])
				dfs(i, a[i]);
		cout << ans;
	}
	
	return 0;
 } 
