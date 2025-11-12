#include <iostream>
using namespace std;
int n,m,a[102],z;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int qw = 1,ans = 0,c = 0,r = 0;
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
		if (i >= 2)
		{
			ans = max(a[1],a[i]);
			if (ans == a[i])
			{
				qw++;
			}
		}
	}
	ans -= ans;
	c += qw/n;
	ans += qw%n;
	if (ans != 0)
	{
		c += 1;
	}
	if (c%2 == 0)
	{
		r += n-ans+1;
	}
	else
	{
		r += ans;
	}
	cout << c << " " << r;
	return 0;
}
