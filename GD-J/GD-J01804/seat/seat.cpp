#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int R, cnt = 1;
	cin >> R;
	for (int i = 2; i <= n * m; i++)
	{
		int x;
		cin >> x;
		if (x > R)
		{
			cnt++;
		}
	}
	int lie = (cnt - 1) / n + 1, hang = cnt % n;
	if (hang == 0)
	{
		hang = n;
	}
	if (lie % 2 == 1)
	{
		cout << lie << " " << hang;
	}
	else
	{
		cout << lie << " " << n - hang + 1;
	}
	return 0;
}
