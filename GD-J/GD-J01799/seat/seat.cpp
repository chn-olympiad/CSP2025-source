#include <bits/stdc++.h>
using namespace std;
struct abc
{
	int shu, id;
}a[15];
int n, m, jsq=0, h=0, l=1;
bool cmp(abc &a , abc &b)
{
	return a.shu>b.shu;
}
abc ans[15][15];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int i;
	cin >> n >> m;
	for (i=1; i<=n*m; i++)
	{
		cin >> a[i].shu;
		a[i].id=i;
	}
	sort (a+1, a+n*m+1, cmp);
	while (jsq<=n*m)
	{
		jsq++;
		if (l%2==1)
		{
			h++;
		}
		else
		{
			h--;
		}
		ans[h][l].id=a[jsq].id;
		if ((h==n && (l%2)) || (h==1 && !(l%2)))
		{
			l++;
			if (l%2==1)
			{
				h--;
			}
			else
			{
				h++;
			}
		}
	}
	for (i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (ans[i][j].id==1)
			{
				cout << j << ' ' << i;
			}
		}
	}
	return 0; 
} 
