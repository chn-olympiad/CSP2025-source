#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
inline ll read()
{
	ll x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c))
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c))
	{
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline void write(ll x)
{
	if (x < 0)
	{
		x = -x;
		putchar('-');
	}
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
struct node
{
	int c, v;
}a[N][5];
int T, n, t;
int jiang[N];
vector<int> clu[5];
ll ans;
bool vis[N];
bool cmp(node x, node y)
{
	return x.v > y.v;
}
bool cmp2 (int x, int y)
{
	return x > y;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while (T--)
	{
		for (int i = 1; i <= 3; i++) clu[i].clear();
		n = read();
		ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
			{
				t = read();
				a[i][j] = {j, t};
			}
		for (int i = 1; i <= n; i++) sort(a[i] + 1, a[i] + 1 + 3, cmp);
		for (int i = 1; i <= n; i++) jiang[i] = a[i][1].v - a[i][2].v;
		for (int i = 1; i <= n; i++)
		{
			int fir = a[i][1].c;
			clu[fir].push_back(jiang[i]);
			ans += a[i][1].v;
		}
		for (int i = 1; i <= 3; i++) sort(clu[i].begin(), clu[i].end(), cmp2);
		for (int i = 1; i <= 3; i++)
		{
			if (clu[i].size() <= n / 2) continue;
			else
			{
				while (clu[i].size() > n / 2) 
				{
					ans -= clu[i].back();
					clu[i].pop_back();
				}
			 } 
		}
		write(ans), putchar('\n');
	}
	return 0;
}
