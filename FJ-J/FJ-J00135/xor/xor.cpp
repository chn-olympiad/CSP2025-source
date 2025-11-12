#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N = 5e6 + 10;
long long n, k, a[N], sum[N], ans, now;
bool vis[N];
bool check(int x, int y)
{
	for (int i = x; i <= y; i++)
	{
		if (vis[i] == true) return false;
	}
	return true;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for (int len = 1; len <= n; len++)
	{
		for (int l = 1; l + len - 1 <= n; l++)
		{
			int r = l + len - 1;
			now = sum[r] ^ sum[l - 1];
			if (now == k && check(l, r))
			{
				for (int k = l; k <= r; k++) vis[k] = true;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}