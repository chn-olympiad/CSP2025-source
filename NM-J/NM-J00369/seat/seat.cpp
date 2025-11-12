#include <bits/stdc++.h>
using namespace std;
int n,m;
int x,seat,pos;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int csp = n * m;
	for (int i = 1;i <= csp;i++)
		cin >> a[i];
	x = a[1];
	sort(a + 1,a + csp + 1);
	for (int i = csp;i >= 1;i--)
	{
		seat++;
		if (a[i] == x)
			pos = seat;
	}
	int x = pos / n;
	if (x == 0)
		x = 1;
	if (pos % n != 0)
		x++;
	int y;
	if (x % 2 == 1)
		y = pos % n;
	else
		y = n - pos % n + 1;
	if (y == 0)
		y = m;
	cout << x << " " << y;
	return 0;
}
