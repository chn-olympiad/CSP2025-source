#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100 + 5;
int a[N];

void search(int n, int m, int tgt)
{
	int cur = 0;
	for (int i = 1; i <= m; ++i) // col
	{
		if (i % 2 == 1) // row
		{
			for (int j = 1; j <= n; ++j)
			{
				if (a[++cur] == tgt)
				{
					cout << i << " " << j << endl;
					return;
				}
			}
		}
		else
		{
			for (int j = n; j >= 1; --j)
			{
				if (a[++cur] == tgt)
				{
					cout << i << " " << j << endl;
					return;
				}
			}
		}
	}
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) cin >> a[i];
	int tgt = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	search(n, m, tgt);
	return 0;
}
