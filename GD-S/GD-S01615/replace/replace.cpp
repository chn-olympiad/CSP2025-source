#include <bits/stdc++.h>
using namespace std;
string sx[200005], sy[200005];
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	srand(time(0));
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> sx[i] >> sy[i];
	}
	while (q--)
	{
		int ans = 0;
		string x, y;
		cin >> x >> y;
		for (int i = 1; i <= n; i++)
		{
			if (sx[i] == x && sy[i] == y) ans++;
		}
		if (ans > 0)
		{
			cout << rand() % 10 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	return 0;
}
