#include <bits/stdc++.h>
using namespace std;
struct Node 
{
	int s,bh;
} a[100005];
bool cmp(Node a,Node b)
{
	return a.s > b.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int T = 1;
	while (T--)
	{
		int n,m,cnt = 0;
		cin >> n >> m;
		for (int i = 1;i <= n * m;i++) a[i].s = a[i].bh = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= m;j++)
			{
				cnt++;
				a[cnt].bh = cnt;
				cin >> a[cnt].s;
			}
		}
		sort(a + 1,a + cnt + 1,cmp);
		int x = 1,y = 0;
		for (int i = 1;i <= cnt;i++)
		{
			if (x % 2 == 1) y++;
			else y--;
			if (a[i].bh == 1)
			{
				cout << x << ' ' << y << '\n';
				break;
			}
			if (y == n && x % 2 == 1) x++,y = n + 1;
			if (y == 1 && x % 2 == 0) x++,y = 0;
		}
	}
	return 0;
}

