#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a, b, c;
}s[100001];
int t, n, x, num1, num2, num3;
signed main()
{
	freopen("club.in", "r", "std.in");
	freopen("club.out", "w", "std.out");
	scanf("%d", &t);
	while(t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i].a >> s[i].b >> s[i].c;
			if (s[i].a >= s[i].b && s[i].c <= s[i].a)
			{				
				if (num1 >= n / 2)
				{
					if (s[i].b > s[i].c && num2 < n / 2)
					{
						x += s[i].b;
						num2++;
					}
					else
					{
						x += s[i].c;
						num3++; 
					}
				}
				else
				{
					x += s[i].a;
					num1++;
				}
			}
			else if (s[i].a <= s[i].b && s[i].c <= s[i].b)
			{
				if (num2 >= n / 2)
				{
					if (s[i].a > s[i].c && num1 < n / 2)
					{
						x += s[i].a;
						num1++;
					}
					else
					{
						x += s[i].c;
						num3++;
					}
				}
				else
				{
					x += s[i].b;
					num2++;
				}
			}
			else
			{
				if (num3 >= n / 2)
				{
					if (s[i].a > s[i].b && num1 < n / 2)
					{
						x += s[i].a;
						num1++;
					}
					else
					{
						x += s[i].b;
						num2++;
					}
				}
				else
				{
					x += s[i].c;
					num1++;
				}
			}			
		}
		printf("%d\n", x);
		x = 0;
		num1 = num2 = num3 = 0;
	}
	return 0;
} 
