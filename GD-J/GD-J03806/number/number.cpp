#include <bits/stdc++.h>
using namespace std;

const int N = 200000, M = 5001, inf = 0x3f3f3f3f, dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0}, mod = 1e9 + 7;

int c[M];

signed main ()
{
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
//	freopen ("number4.out", "w", stdout);
//	freopen ("number4.in", "r", stdin);
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size ();
	s = " " + s;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			c[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = c[i]; j >= 1; j--)
		{
			cout << i;
		}
	}
	return 0;
}

/*
5

5

----------

290es1q0

92100

----------


*/
