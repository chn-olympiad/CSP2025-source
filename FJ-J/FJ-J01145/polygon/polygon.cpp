#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int M = 1e4 + 5;
int n;
long long x;
int a[N],b[M][M],c[M];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool f = true;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] != 1) f = false;
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)
	{
		x += a[i];
	}
	if(n == 3)
	{
		if(a[n] * 2 < x)
		{
			cout << 1;
		}
		else cout << 0;
	}
	else if(f == true)
	{
		b[1][1] = 1;
		b[2][1] = 1;
		b[2][2] = 2;
		b[2][3] = 1;
		c[1] = 1;
		c[2] = 3;
		if(n == 4)
		{
			cout << c[1] + c[2];
			return 0;
		}
		for(int i = 3;i <= n - 2;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				if(b[i - 1][j] == 0 && b[i - 1][j - 1] == 0) break;
				else
				{
					b[i][j] = b[i - 1][j] + b[i - 1][j - 1];
					c[i] += b[i][j];
				}
			}
			c[i] -= 1;
		}
		long long e1 = 0,e2 = 0;
		for(int i = 1;i <= n - 2;i++)
		{
			e1 += c[i];
			e2 += e1;
		}
		cout << e2;
	}
	return 0;
}
