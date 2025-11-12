#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 110,M = 20;
int n,m;
int a[N];
int R;
int vis[M][M];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	R = a[1];
	sort(a+1,a+n*m+1,cmp);
	int Head = 1;
	for (int j = 1;j <= m;j++)
	{
		if (j % 2 == 1)
		{
			for (int i = 1;i <= n;i++)
			{
				vis[i][j] = a[Head];
				Head++;
				if (vis[i][j] == R)
				{
					cout << j << " " << i;
					return 0;
				}
			}
		}
		if (j % 2 == 0)
		{
			for (int i = n;i >= 1;i--)
			{
				vis[i][j] = a[Head];
				Head++;
				if (vis[i][j] == R)
				{
					cout << j << " " << i;
					return 0;
				}
			}
		}
	}
	return 0;
}
