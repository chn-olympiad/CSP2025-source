#include<bits/stdc++.h>
using namespace std;
int t,n,a[3][100001],s[3],max[2][100001],da[20001][3],nb;
long long maxa[3];
void g0()
{
	for(int i = 1;i <= 20000;i++)
		for(int j = 0;j <= 2;j++)
			da[i][j] = 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for(int i = 1;i <= t;i++)
	{
		cin >> n;
		for(int j = 1;j <= n;j++)
			cin >> a[0][j] >> a[1][j] >> a[2][j];
		for(int j = 1;j <= n;j++)
		{
			maxa[0] += a[0][j];
			maxa[1] += a[1][j];
			maxa[2] += a[2][j];
		}
		for(int j = 1;j <= n;j++)
		{
			s[a[0][j]]++;
			s[a[1][j]]++;
			s[a[2][j]]++;
		}
		if(s[0] <= n / 2 && s[1] <= n / 2 && s[2] <= n/ 2)
		{
			if(maxa[0] > maxa[1] && maxa[0] > maxa[2])
				nb = maxa[0];
			if(maxa[1] > maxa[2] && maxa[1] > maxa[0])
				nb = maxa[1];
			if(maxa[2] > maxa[1] && maxa[2] > maxa[0])
				nb = maxa[2];
		}
		else
		{
			int a1 = 1,a2 = 1,a3 = 1;
			long long b1 = 0,b2 = 0,b3 = 0;
			for(int k = 0;k <= 2;k++)
				for(int l = 1;l <= n;l++)
					da[a[k][l]][k]++;
			for(int j = 1;j <= n;j++)
			{
				for(int k = 1;k <= da[j][0];k++)
				{
					if(a1 <= n / 2)
					{
						b1 += j;
						a1++;
					}
				}
				g0();
				for(int k = 1;k <= da[j][1];k++)
				{
					if(a2 <= n / 2)
					{
						b2 += j;
						a2++;
					}
				}
				g0();
				for(int k = 1;k <= da[j][2];k++)
				{
					if(a3 <= n / 2)
					{
						b3 += j;
						a3++;
					}
				}
			}
			if(b1 >= b2 && b1 >= b3)
				nb = b1;
			else if(b2 >= b1 && b2 >= b3)
				nb = b2;
			else if(b3 >= b2 && b3 >= b1)
				nb = b3;
		}
		if(i < t)
			cout << nb << endl;
		else
			cout << nb;
	}
	return 0;
}