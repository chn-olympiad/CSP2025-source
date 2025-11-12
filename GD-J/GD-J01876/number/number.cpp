#include <bits/stdc++.h>
#define int long long
using namespace std;

char c;
int n, a[1000006];

signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while (cin >> c)
	{
		if (c >= '0' && c <= '9')a[++n] = (c - '0');
	}
	sort(a + 1, a + n + 1, greater <int> ());
	if (a[1] == 0)
	{
		cout << 0;
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			cout << a[i];
		}
	}
	return 0;
}
