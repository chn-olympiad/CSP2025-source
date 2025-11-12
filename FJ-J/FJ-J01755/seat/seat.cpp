#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], b[15][15], num;
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int z = n * m;
	for(int i = 1;i <= z;i++)
	{
		cin >> a[i];
	}
	num = a[1];
	if(z == 1)
	{
		cout << 1 << " " << 1;
		return 0;
	}
	sort(a + 1,a + z + 1,cmp);
	int pos = 0;
	for(int i = 1;i <= m;i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1;j <= n;j++)
			{
				b[j][i] = a[++pos];
			}
		}
		else
		{
			for(int j = n;j >= 1;j--)
			{
				b[j][i] = a[++pos];
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			if(b[i][j] == num)
			{
				cout << j << " " << i;
				break;
			}
		}
	}
	return 0;
}
