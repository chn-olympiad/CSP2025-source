#include <bits/stdc++.h>
using namespace std;
int n, m, a, x, sum, w, h;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> a;
	sum = 1;
	for (int i = 2; i <= n * m; i++)
	{
		cin >> x;
		if(x > a)
		{
			sum++;
		}
	}
	w = (int)(sum / n);
	sum -= w * n;
	if (sum == 0)
	{
		if(w % 2 == 0)
		{
			cout << w << " " << "1" << '\n';
		}
		else
		{
			cout << w << " " << n << '\n';
		}
		return 0;
	}
	if (w % 2 == 0)
	{
		cout << w + 1 << " " << sum << '\n';
		return 0;
	}
	else if(w % 2 == 1)
	{
		cout << w + 1 << " " << n - sum + 1 << '\n';
		return 0;
	}
}
