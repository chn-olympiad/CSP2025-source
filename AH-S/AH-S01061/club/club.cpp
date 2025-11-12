#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, sum, tot, tot2, tot3, h, temp;
struct Node
{
	int x, y, z;
}a[100001];
struct Appl
{
	int cnt, key;
	char id;
}lx[100001], ly[100001], lz[100001];
bool cmp(Appl x, Appl y)
{
	return x.cnt > y.cnt;
}
bool cmp1(Appl x, Appl y)
{
	return x.cnt > y.cnt;
}
bool cmp2(Appl x, Appl y)
{
	return x.cnt > y.cnt;
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		cin >> n;
		tot = 0, tot2 = 0, tot3 = 0, h = 0;
		sum = 0;
		memset(lx, 0, sizeof(lx));
		memset(ly, 0, sizeof(ly));
		memset(lz, 0, sizeof(lz));
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			int p = max(max(a[i].x, a[i].y), a[i].z);
			if (p == a[i].x)
			{
				sum += a[i].x;
				lx[++tot].cnt = min(a[i].x - a[i].y, a[i].x - a[i].z);
				lx[tot].key = i;
				if (a[i].x - a[i].y >= a[i].x - a[i].z)
				{
					lx[tot].id = 'y'; 
				}
				else
				{
					lx[tot].id = 'z';
				}
				continue;
 			}
			if (p == a[i].y)
			{
				sum += a[i].y;
				ly[++tot2].cnt = min(a[i].y - a[i].x, a[i].y - a[i].z);
				ly[tot2].key = i;
				if (a[i].y - a[i].x >= a[i].y - a[i].z)
				{
					ly[tot2].id = 'x'; 
				}
				else
				{
					ly[tot2].id = 'z';
				}
				continue;
			}
			if (p == a[i].z)
			{
				sum += a[i].z;
				lz[++tot3].cnt = min(a[i].z - a[i].x, a[i].z - a[i].y);
				lz[tot3].key = i;
				if (a[i].z - a[i].x >= a[i].z - a[i].y)
				{
					lz[tot3].id = 'x'; 
				}
				else
				{
					lz[tot3].id = 'y';
				}
			}
		}
		sort(lx + 1, lx + tot + 1, cmp);
		sort(ly + 1, ly + tot2 + 1, cmp1);
		sort(lz + 1, lz + tot3 + 1, cmp2);
		for (int m = 1; m < 5; m++)
		{
			if (tot > (n / 2))
			{
				h = tot - (n / 2), temp = tot;
				for (int i = tot; i >= (n / 2) + 1 && i > 0; i--)
				{
					sum -= lx[i].cnt;
					if (lx[i].id == 'y')
					{
						ly[++tot2].cnt = a[lx[i].key].y;
					}
					if (lx[i].id == 'z')
					{
						lz[++tot3].cnt = a[lx[i].key].z;
					}
					tot--;
				}
			}
			if (tot2 > (n / 2))
			{
				h = tot2 - (n / 2), temp = tot2;
				for (int i = tot2; i >= temp - h + 1 && i > 0; i--)
				{
					sum -= ly[i].cnt;
					if (lx[i].id == 'x')
					{
						lx[++tot].cnt = a[ly[i].key].x;
					}
					if (ly[i].id == 'z')
					{
						lz[++tot3].cnt = a[lx[i].key].z;
					}
					tot2--;
				}
			}
			if (tot3 > (n / 2))
			{
				h = tot3 - (n / 2), temp = tot3;
				for (int i = tot3; i >= temp - h + 1 && i > 0; i--)
				{
					if (i < 0)
					{
						cout << i;
					}
					sum -= lz[i].cnt;
					if (lz[i].id == 'x')
					{
						lx[++tot].cnt = a[lz[i].key].x;
					}
					if (lz[i].id == 'y')
					{
						ly[++tot2].cnt = a[lz[i].key].y;
					}
					tot3--;
				}
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
