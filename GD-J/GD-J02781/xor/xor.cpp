#include <iostream>
#include <cstdio>
using namespace std;
int a[500005],cnt,maxx = -1;
int kfen[25],kcnt,afen[500005][25],acnt[500005],sum[500005][25];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		maxx = max(maxx,a[i]);
	}
	if (maxx == 0 || maxx == 1)
	{
		if (k == 1)
		{
			for (int i = 1;i <= n;i++)
			{
				if (a[i] == 1)
					cnt++;
			}
			cout << cnt;
			return 0;
		}
		else if (k == 0)
		{
			for (int i = 1;i <= n;i++)
			{
				if (a[i] == 0)
					cnt++;
			}
			for (int i = 1;i <= n;i++)
			{
				if (i != n && a[i] == 1 && a[i + 1] == 1)
					cnt++,i++;
			}
			cout << cnt;
			return 0;
		}
		else
		{
			cout << 0;
			return 0;
		}
	}
	else
	{
		while(k)
		{
			kfen[++kcnt] = k % 2;
			k /= 2;
		}
		for (int i = 1;i <= n;i++)
		{
			int xx = a[i];
			while(xx)
			{
				afen[i][++acnt[i]] = xx % 2;
				xx /= 2;
			}
			for (int j = 1;j <= 20;j++)
			{
				sum[i][j] = sum[i - 1][j] + afen[i][j];
			}
		}
		/*
		for (int i = 1;i <= n;i++)
		{
			cout << a[i] << ":" << acnt[i] << ":";
			for (int j = 1;j <= 20;j++)
			{
				cout << afen[i][j];
			}
			cout << endl;
		}
		*/
		int dao = 1;
		for (int j = 1;j <= n;j++)
		{
			for (int i = dao;i <= j;i++)
			{
				bool canfen = 1;
				for (int p = 1;p <= 20;p++)
				{	
					if ((sum[j][p] - sum[i - 1][p]) % 2 != kfen[p])
					{
						canfen = 0;
						break;
					}
				}
				if (canfen == 1)
				{
					cnt++;
					dao = j + 1;
					//cout << i << " " << j << endl;
					break;
				}
			}
		}
		cout << cnt;
		return 0;
	}
}
