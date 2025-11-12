#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m;
int a[105];
bool cmp(int a, int b) { return a > b; }
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < m * n; i++) cin >> a[i];
	int t = a[0];
	sort(a, a + m * n, cmp);
	for (int i = 0; i < m * n; i++)
	{
		if (a[i] == t)
		{
			i++;
			int c, r;
			if (i % n != 0) c = i / n + 1;
			else c = i / n;
			if (c % 2 == 0) r = n + 1 - (i % n);
			else if (i % n != 0) r = i % n;
			else r = n;
			cout << c << ' ' << r << endl;
			return 0;
		}
	}
	return 0;
}
