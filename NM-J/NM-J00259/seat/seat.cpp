#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int sum[15][15];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >>n >>m;
    for (int i = 1;i <= n*m;i++)
    {
        cin >> a[i];
    }
    int d = a[1];
    sort(a +1,a + n*m +1,cmp);
    int num = 1;
    int l = 1,j = 1;
	while (num <= n*m)
	{
		sum[l][j] = num;
		if (j % 2 == 1)
		{
			if (l == n)
			{
				j++;
				num++;
				continue;
			}
			else
				l++;
		}
		else
		{
			if (l == 1)
			{
				j++;
				num++;
				continue;
			}
			else
				l--;
		}
		num++;
	}
	int  k = 0;
	for (int i = 1;i <= n*m;i++)
	{
		if (d == a[i])
		{
			k = i;
			break;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if (sum[i][j] == k)
			{
				cout << j << " " << i;
				return 0;
			}
		}
	}
    return 0;
}
