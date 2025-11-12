#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, front = 0, hg, c = 0, r = 0;
	cin >> n >> m;
	long a[m * n];
	for (int i = 0; i <m * n; i ++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i ++)
	{
		if (a[i] > a[0]) front ++;
	}
	hg = front + 1;
	//cout << hg;
	if (hg / m != 0) c = hg / m + 1;
	else c = hg / m;
	if (hg < n) r = hg;
	else if ((hg % n == 1 && (hg - 1) / n % 2 == 1)or(hg % n == 0 && (hg / 4) % 2 == 1)) r = 1;
	else if ((hg % n == 1 && (hg - 1) / n % 2 == 0)or(hg % n == 0 && (hg / 4) % 2 == 0)) r = n;
	cout << c <<" " << r;
	return 0;
}
