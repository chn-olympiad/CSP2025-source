#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int n,m,a[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n * m;i++)
	{
		cin >> a[i];
	}
	int xr = a[0];
	for (int i = 0;i < n * m;i++)
	{
		int ans = 0;
		if(a[i] < a[i + 1])
		{
			ans = a[i];
			a[i] = a[i + 1];
			a[i + 1] = ans;
		}
		else
		{
			continue;
		}
	}
	int wzzl = 0;
	for (int i = 0;i < n * m;i++)
	{
		if(a[i] == xr)
		{
			wzzl = i + 1;
		}
	}
	int c = 0,r = 0;
	int jg = wzzl / n;
	int ys = wzzl % n;
	if((jg + 1) % 2 == 0 && ys != 0)
	{
		if(ys == 0)
		{
			c = jg;
			r = 1;
		}
		else
		{
			c = jg + 1;
			r = n - ys + 1;
		}
	}
	else
	{
		if(ys == 0)
		{
			
			c = jg;
			r = n;
		}
		else
		{
			c = jg + 1;
			r = ys;
		}
	}
	if (n * m == 1)
	{
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	cout << c << " " << r << endl;
	return 0;
}