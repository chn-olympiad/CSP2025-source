#include <bits/stdc++.h> 
using namespace std;
int n, m;
int a[105];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
	{
		cin >> a[i];
	}
	int x = a[1];
	sort(a+1, a+n*m+1, cmp);
	int hang = 0, lie = 1;
	for (int i = 1; i <= n*m; i++)
	{
		if (lie % 2 == 1)
		{
			if (hang + 1 > n)
			{
				hang = n;
				lie++;
			}
			else
			{
				hang++;
			}
		}
		else
		{
			if (hang - 1 == 0)
			{
				lie++;
				hang = 1;
			}
			else
			{
				hang--;
			}
		}
		if (a[i] == x)
		{
			cout << lie << " " << hang << endl;
			break;
		} 
	}
	return 0;
}
