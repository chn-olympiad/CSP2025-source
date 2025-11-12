#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 600010;
ll n, k, ans = 0, max_n = -1, last_i;
ll a[N];
bool vis[N] = {false};
inline ll h(ll l, ll r)
{
	ll ans = a[l];
	for (int i = l + 1; i <= r; ++i)
	{
		ans ^= a[i];
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		max_n = max(max_n, a[i]);
	}
	if (k == 0)
	{
		ll cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] == 0)
			{
				++cnt;
			}
		}
		cout << cnt;
		exit(0);
	}
	if (max_n <= 1)
	{
		if (k == 1)
		{
			ll cnt = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (a[i] == 1)
				{
					++cnt;
				}
			}
			cout << cnt;
			exit(0);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] == k)
		{
			++ans;
		}
	}
	stable_sort(a + 1, a + 1 + n);
	ll l = 1, s = 1;
	for (int i = l; i <= n; ++i)
	{
		for (int j = s; j <= i; ++j)
		{
			if (h(j, i) == k)
			{
				++ans;
				s = j + 1;
				l = i + 1;
				break;
			}
		}
	}
	cout << ans - 1;
	return 0;
}
