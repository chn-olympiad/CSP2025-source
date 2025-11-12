#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<int> vct(n*m);
	for (int i = 0; i < n*m; ++i)
		cin >> vct[i];

	int R = vct[0];
	sort(vct.begin(), vct.end(), [](int a, int b)
		{
			return a > b;
		});
	

	int l = 0;

	for (int i = 0; i < n*m; ++i)
	{
		if (vct[i] == R)
		{
			l = i;
			break;
		}
	}

	int c = l / n + 1, row = l % n;
	if (c % 2 == 0)
		row = n - row;
	else
		row++;

	cout << c << ' ' << row << '\n';

	return 0;
}