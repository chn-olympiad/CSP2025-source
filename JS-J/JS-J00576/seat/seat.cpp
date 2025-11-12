#include <bits/stdc++.h>
using namespace std;
const int N = 256;
int n, m, a[N], t, b[N], pos, r, c;
int main()
{
freopen("seat.in", "r", stdin);
freopen("seat.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n * m ; i++)
	   scanf ("%d", &a[i]);
	t = a[1];
	sort(a + 1, a + n * m + 1);
	for (int i = 1; i <= n * m; i++)
		b[i] = a[n * m - i + 1];
	for (int i = 1; i <= n * m; i++)
	{
	    if (t == b[i])
	    {
			pos = i;
			break;
		}
	}
	r = ceil(pos * 1.0 / n);
	c = pos % n;
	if (r & 1)
	{
		if (c == 0) cout << r << " " << n;
		else cout << r << " " << c;
	}
	else
	{
		if (c == 0) cout << r << " " << 1;
		else cout << r << " " << n - c + 1;
	}
	return 0;
}

