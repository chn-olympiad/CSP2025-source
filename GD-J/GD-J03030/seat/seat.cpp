#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[15][15];
	int b[1000];
	for (int i = 1;i <= n*m;i++)
	{
		cin >> b[i];
	}
	int x = b[1];
	int g = n*m+1;
	sort(b+1,b+g);
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			a[j][i] = b[--g];
			if (a[j][i] == x)
			{
				cout <<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}
