#include <cstdio>
#include <algorithm>

const int N = 107;

int n, m, k, xh, plc;
int a[N], col, rows;

using namespace std;

int main ()
{
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	scanf ("%d %d", &n, &m);
	k = n * m;
	for (int i = 1; i <= k; i ++)
		scanf ("%d", &a[i]);
	xh = a[1];
	sort (a + 1, a + k + 1);
	for (int i = 1; i <= k; i ++)
		if (a[i] == xh)
		{
			plc = i;
			break;
		}
	plc = k - plc + 1;
	col = plc / n;
	int v = plc % n;
	if (v > 0)
		col ++;
	else
		v = n; 
	if (col & 1)
		rows = v;
	else
		rows = n - v + 1;
	printf ("%d %d", col, rows);
}
