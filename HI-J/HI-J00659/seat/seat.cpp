#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[15][15],f[105];
int cmp(int s,int t)
{
	return s > t;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n * m;i++)
	{
		cin >> f[i];
		if (i == 1)
		{
			ans = f[i];
		}
	}
	sort(f + 1,f + n * m + 1,cmp);
	int sum = 1;
	for (int i = 1;i <= m;i++)
	{
		if (i % 2 == 1)
		{
			for (int j = 1;j <= n;j++)
			{
				a[j][i] = f[sum];
				sum++;
				if (a[j][i] == ans)
				{
					cout << i <<" " <<  j << endl;
					break;
				}
			}
		}
		if (i % 2 == 0)
		{
			for (int j = n;j >= 1;j--)
			{
				a[j][i] = f[sum];
				sum++;
				if (a[j][i] == ans)
				{
					cout << i <<" " << j<< endl;
					break;
				}
			}
		}
	}
	return 0;
}
