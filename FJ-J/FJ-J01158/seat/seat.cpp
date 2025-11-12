#include<bits/stdc++.h>
using namespace std;
int a[10005]{0},m,n,r;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	r = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for (int i = 1;i <= m;i++)
	{
		if (i % 2 == 0)
		{
			sort(a + (i - 1) * n + 1,a + i * n + 1);
		}
	}
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (a[(i - 1) * n + j] == r)
			{
				cout << i << " " << j << endl;
				return 0;    
			}
		}
	}
	return 0;
}
