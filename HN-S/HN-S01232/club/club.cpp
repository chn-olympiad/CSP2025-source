#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 50;
int t, n;
struct node{
	int a, b, c;
	int mx1 = 0, mx2 = 0;
} a[N];
bool cmp(node A, node B)
{
	return A.mx1 + B.mx2 > B.mx1 + A.mx2;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
			int b[5];
			b[1] = a[i].a, b[2] = a[i].b, b[3] = a[i].c;
			sort(b + 1, b + 4);
			a[i].mx1 = b[3], a[i].mx2 = b[2];
		}
		sort(a + 1, a + 1 + n, cmp);
		int ans = 0, sum1 = 0, sum2 = 0, sum3 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i].a == a[i].mx1)
			{
				if (sum1 == n / 2)
				{
					if (a[i].b == a[i].mx2)
					{
						sum2++;
						ans += a[i].b;
					} 
					else
					{
						sum3++;
						ans += a[i].c;
					}
				}
				else
				{
					sum1++;
					ans += a[i].a;
				}
			}
			else if (a[i].b == a[i].mx1)
			{
				if (sum2 == n / 2)
				{
					if (a[i].a == a[i].mx2)
					{
						sum1++;
						ans += a[i].a;
					}
					else
					{
						sum3++;
						ans += a[i].c; 
					}
				}
				else
				{
					sum2++;
					ans += a[i].b;
				}
			}
			else if (a[i].c == a[i].mx1)
			{
				if (sum3 == n / 2)
				{
					if (a[i].a == a[i].mx2)
					{
						sum1++;
						ans += a[i].a;
					}
					else
					{
						sum2++;
						ans += a[i].b;
					}
				}
				else
				{
					sum3++;
					ans += a[i].c;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
