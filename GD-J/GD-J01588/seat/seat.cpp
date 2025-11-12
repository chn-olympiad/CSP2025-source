#include <bits/stdc++.h>

using namespace std;
const int N = 1e2 + 5;

int n, m, score, c = 1, r = 1;
int a[N];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in", "r", stdin);
	freo4pen("seat.out", "w", stdout);
	cin >> n >> m >> score;
	a[1] = score;
	for (int i = 2; i <= n * m; i++)
		cin >> a[i];
	sort(a + 1, a + n * m + 1, cmp);
	if (a[1] == score) cout << 1 << " " << 1;
	else
	{
		for (int i = 2; i <= n * m; i++)
		{
			if (c & 1)
			{
				r ++;
				if (r > n)
				{
					r = n;
					c ++;
				}
			}
			else
			{
				r --;
				if (r < 1)
				{
					r = 1;
					c ++;
				}
			}
			if (a[i] == score) break;
			//cout << a[i] << " " << c << " " << r << endl; 
		}
		cout << c << " " << r;
	}
	return 0;
}
//O(nm)
// 3 3
// 90 100 98 47 55 63 97 91 89
//3 3
//94 95 96 97 98 99 100 93 92
