#include <iostream>
#include <cstdio>
using namespace std;
const int N = 5e5+5;
int n, m, x[N], num, ans;
bool vis[N];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++)
	{
		num = x[i];
		if (vis[i]) continue;
		for (int j = i, k = i; j >= 1 && k <= n; j--, k++)
		{
			if (vis[j] || vis[k]) break;
			num ^= x[j] ^ x[k];
			if (num == m)
			{
				ans++;
				for (int l = j; l <= k; l++) vis[l] = true;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		num = 0;
		if (vis[i]) continue;
		for (int j = i-1, k = i; j >= 1 && k <= n; j--, k++)
		{
			if (vis[j] || vis[k]) break;
			num ^= x[j] ^ x[k];
			if (num == m)
			{
				ans++;
				for (int l = j; l <= k; l++) vis[l] = true;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
