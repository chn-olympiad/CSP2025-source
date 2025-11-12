#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int t, n, a[N], b[N], c[N], cnt[int('g')], ans;
vector<char> ch[N];
void get(int i, int a, int b, int c)
{
	if (a > b && b > c && a > c)
	{
		ch[i][1] = 'a';
		ch[i][2] = 'b';
		ch[i][3] = 'c';
	}
	else if (a > b && c > b && a > c)
	{
		ch[i][1] = 'a';
		ch[i][2] = 'c';
		ch[i][3] = 'b';
	}
	else if (b > a && a > c && b > c)
	{
		ch[i][1] = 'b';
		ch[i][2] = 'a';
		ch[i][3] = 'c';
	}
	else if (b > a && c > a && b > c)
	{
		ch[i][1] = 'b';
		ch[i][2] = 'c';
		ch[i][3] = 'a';
	}
	else if (c > a && a > b && c > b)
	{
		ch[i][1] = 'c';
		ch[i][2] = 'a';
		ch[i][3] = 'b';
	}
	else
	{
		ch[i][1] = 'c';
		ch[i][2] = 'b';
		ch[i][3] = 'a';
	}
}
int fun(int i, char ch)
{
	if (ch == 'a') return a[i];
	if (ch == 'b') return b[i];
	if (ch == 'c') return c[i];
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		ans = 0;
		memset(cnt, 0, sizeof cnt);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			ch[i].clear();
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
			ch[i].push_back(' ');
			ch[i].push_back(' ');
			ch[i].push_back(' ');
			ch[i].push_back(' ');
			get(i, a[i], b[i], c[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				if (++cnt[ch[i][j]] > n / 2)
				{
					cnt[ch[i][j]]--;
					continue;
				}
				else
				{
					ans += fun(i, ch[i][j]);
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
