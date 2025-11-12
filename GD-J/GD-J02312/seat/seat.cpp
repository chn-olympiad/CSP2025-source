#include <bits/stdc++.h>
using namespace std;
int a[101];
bool cmp(int x, int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i<=n*m; i++)
	{
		cin >> a[i];
	}
	a[0]=a[1];
	sort(a+1, a+n*m+1, cmp);
	for(int i = 1; i<=n*m; i++)
	{
		if(a[i]!=a[0])
		{
			continue;
		}
		int lie = (i+n-1)/n;
		cout << lie << " ";
		if(lie%2)
		{
			if(i%n)
			{
				cout << i%n << endl;
			}
			else
			{
				cout << n << endl;
			}
		}
		else
		{
			if(i%n)
			{
				cout << n+1-i%n << endl;
			}
			else
			{
				cout << 1 << endl;
			}
		}
	}
	return 0;
}
