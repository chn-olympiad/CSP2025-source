#include <bits/stdc++.h>
using namespace std;
int k, n, a[1000020], ans = 1, cnt, maxs;
int main ()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	if (k == 0)
	{
		if (n == 2)
		{
			if (a[1] == a[2]) cout << 2;
			else if (a[1] == 0 || a[2] == 0) cout << 1;
			else cout << 0;
			return 0;
		}
		for (int i = 2;  i <= n; i ++)
		{
			if (a[i] == a[i - 1] && i - 1 == cnt) ans ++, cnt = i;
			if (i - 1 != cnt) maxs = max(ans, maxs), ans = 0;
		}
		cout << maxs;
		return 0;
	}
	else if (k == 1)
	{
		for (int i = 2;  i<= n; i ++)
		{
			if (a[i] + 1 == a[i - 1] || a[i - 1] + 1 == a[i]) ans ++, i ++, cnt = i;
			if (i - 1 != cnt) maxs = max(ans, maxs), ans = 0;
		}
		cout << maxs;
		return 0;
	}
	cout << 0;
	return 0;
}
