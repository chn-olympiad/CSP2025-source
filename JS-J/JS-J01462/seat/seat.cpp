#include <bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int g = a[1];
	sort(a + 1, a + n * m + 1, greater < int >());
	for (int i = 1; i <= n * m; i++)
		if (g == a[i]) 
		{
			g = i;
			break;
		}
	int x = (g + n - 1) / n;
	int y = g - (x - 1) * n;
	if (x % 2 == 0) y = m - y + 1;
	cout << x << ' ' << y << '\n';
    return 0;
}
