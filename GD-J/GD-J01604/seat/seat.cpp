#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, g, r, k, residue, ansr, ansc, f[105];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> f[i];
	g = f[1];
	sort(f + 1, f + n * m + 1);
	r = lower_bound(f + 1, f + n * m + 1, g) - f;
	k = n * m - r + 1;
	ansc = (k % n == 0 ? k / n : k / n + 1);
	residue = (k % n == 0 ? n : k % n);
	if (ansc % 2 == 0)
	{
		ansr = n - residue + 1;
	}
	else
	{
		ansr = residue;
	}
	cout << ansc << " " << ansr;
	return 0;
}
