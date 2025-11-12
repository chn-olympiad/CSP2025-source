#include <iostream>
using namespace std;
int a[105];
int xr;
int mc;
int n,m;
int h,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> xr;
	a[1] = xr;
	mc = 1;
	for (int i = 2;i <= n * m;i ++)
	{
		cin >> a[i];
		if (a[i] > xr)
		{
			mc ++;
		}
	}
	mc --;
	h = mc / n + 1;
	if (h % 2 == 0)
	{
		l = n - mc % n;
	}
	else
	{
		l = 1 + mc % n;
	}
	cout << h << " " << l;
	return 0;
}
