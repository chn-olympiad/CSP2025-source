#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll md = 998244353;
ll n, a[5005], ans;
int main ()
{
	freopen ("polygon.in", "r", stdin);
	freopen ("polygon.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	if (n == 3 && (a[1] + a[2] + a[3]) > (2 * a[3]))
	{
		cout << 1;
		return 0; 
	}
	else if (n == 3 && (a[1] + a[2] + a[3]) <= (2 * a[3]))
	{
		cout << 0;
		return 0;
	}
	if (a[n] == 1)
	{
		ll cnto = 1, cntr = 1;
		for (int i = 2; i <= n; ++i)
		{
			if (i > 3)
			{
				cnto *= i;
				cnto %= md;
			}
			if (i <= n - 3)
			{
				cntr *= i;
				cntr %= md;
			}
		}
		ll xon = 4, xre = n - 3;
		for (int i = 3; i <= n - 1; ++i)
		{
			ans += cnto / cntr;
			cnto /= xon;
			cntr /= xre;
			xon++;
			xre--;
		}
		cout << ans + 1;
		return 0;
	}
	else
	{
		if (n == 3)
		{
			for (int i = 1; i <= n; ++i)
			{
				for (int j = i + 1; j <= n; ++j)
				{
					for (int k = j + 1; k <= n; ++k)
					{
						if ((i + j + k) > (2 * k))
						{
							ans++;
						}
					}
				}
			}
			return 0;
		}
		else if (n == 4)
		{
			for (int i = 1; i <= n; ++i)
			{
				for (int j = i + 1; j <= n; ++j)
				{
					for (int k = j + 1; k <= n; ++k)
					{
						if ((i + j + k) > (2 * k))
						{
							ans++;
						}
					}
				}
			}
			for (int i = 1; i <= n; ++i)
			{
				for (int j = i + 1; j <= n; ++j)
				{
					for (int k = j + 1; k <= n; ++k)
					{
						for (int kon = k + 1; kon <= n; ++kon)
							if ((i + j + k + kon) > (2 * kon))
							{
								ans++;
							}
					}
				}
			}
			cout << ans;
			return 0;
		}
		else if (n == 5)
		{
			for (int i = 1; i <= n; ++i)
			{
				for (int j = i + 1; j <= n; ++j)
				{
					for (int k = j + 1; k <= n; ++k)
					{
						if ((i + j + k) > (2 * k))
						{
							ans++;
						}
					}
				}
			}
			for (int i = 1; i <= n; ++i)
			{
				for (int j = i + 1; j <= n; ++j)
				{
					for (int k = j + 1; k <= n; ++k)
					{
						for (int kon = k + 1; kon <= n; ++kon)
							if ((i + j + k + kon) > (2 * kon))
							{
								ans++;
							}
					}
				}
			}
			for (int i = 1; i <= n; ++i)
			{
				for (int j = i + 1; j <= n; ++j)
				{
					for (int k = j + 1; k <= n; ++k)
					{
						for (int kon = k + 1; kon <= n; ++kon)
							for (int ktw = kon + 1; ktw <= n; ++ktw)
							if ((i + j + k + kon + ktw) > (2 * ktw))
							{
								ans++;
							}
					}
				}
			}
		}
	}
	return 0;
}