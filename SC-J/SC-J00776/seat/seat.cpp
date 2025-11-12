#include <bits/stdc++.h>
using namespace std;

int n, m, a[105], h, l, cnt, R;
bool cmp(int x, int y)
{
	return x > y;
}

void ans()
{
	if (a[++ cnt] == R)
	{
		cout << l << ' ' << h;
		exit(0);
	}
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n * m; ++ i) cin >> a[i];
	R = a[1];
	
	if (n == 1 && m == 1) cout << "1 1";
	else
	{
		sort(a + 1, a + n * m + 1, cmp);
		for (l = 1; l <= m; ++ l)
		{
			if (l & 1 == 1)
				for (h = 1; h <= n; ++ h) ans();
			else
				for (h = n; h >= 1; -- h) ans();
		}
	}
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}