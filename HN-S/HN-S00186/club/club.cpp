#include<bits/stdc++.h>
using namespace std;
int q, n, s1, s2, s3, ans;
struct E
{
	int x, y, z;
}a[100005];
bool cmp(E m, E p)
{
	return max(max(m.x, m.y), m.z) > max(max(p.x, p.y), p.z);
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			cin >> a[j].x >> a[j].y >> a[j].z;
		}
		sort(a + 1, a + n + 1, cmp);
		for (int j = 1; j <= n; j++)
		{
			if (max(max(a[j].x, a[j].y), a[j].z) == a[j].x)
			{
				if (s1 < (n / 2))
				{
					ans += a[j].x;
					s1++;
				}
				else
				{
					ans += max(a[j].y, a[j].z);
				}
			}
			else if (max(a[j].y, a[j].z) == a[j].y)
			{
				if (s2 < (n / 2))
				{
					ans += a[j].y;
					s2++;
				}
				else
				{
					ans += max(a[j].x, a[j].z);
				}
			}
			else
			{
				if (s3 < (n / 2))
				{
					ans += a[j].z;
					s3++;
				}
				else
				{
					ans += max(a[j].x, a[j].y);
				}
			}
		}
		cout << ans << endl;
		s1 = s2 = s3 = ans = 0;
	}
	return 0;
}
