#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;
const int M = 1e6 + 6;
const int K = 13;
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
	int x, y;
	int w;
}b[M + N * K];
int n, m, k, f[N];
int mp[1005][1005];
int c[K], cc[K][N];
ll ans;
bool is_subA = 1;
bool cmp (node x, node y)
{
	return x.w < y.w;
}
int find(int x)
{
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
void subK()
{
	sort(b + 1, b + 1 + m, cmp);
	for (int i = 1; i <= n; i++) f[i] = i;
	int cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		int x = find(b[i].x), y = find(b[i].y);
		if (x != y)
		{
			f[x] = y;
			cnt++;
			ans += b[i].w;
		}
		if (cnt == n - 1) break;
	}
	write(ans);
}
void subA()
{
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
		{
			if (cc[i][j] == 0)
			{
				for (int l = 1; l <= n; l++)
				{	
					if (mp[j][l] > cc[i][l])
					{
						mp[j][l] = mp[l][j] = cc[i][l];
//						b[++m] = {j, l, cc[i][l]};
					}
				}
					
			}
		}
	int tot = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			if (mp[i][j] < INT_MAX) 
				b[++tot] = {i, j, mp[i][j]};
		}		
	sort(b + 1, b + 1 + tot, cmp);
	for (int i = 1; i <= n; i++) f[i] = i;
	int cnt = 0;
	for (int i = 1; i <= tot; i++)
	{
		int x = find(b[i].x), y = find(b[i].y);
		if (x != y)
		{
			f[x] = y;
			cnt++;
			ans += b[i].w;
		}
		if (cnt == n - 1) break;
	}
	write(ans);
}
int main()
{
	// road
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			mp[i][j] = INT_MAX;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		x = read(), y = read(), z = read();
//		b[i] = {x, y, z};
		mp[x][y] = mp[y][x] = min(mp[x][y], z);
	}
//	int tot = 0;
//	for (int i = 1; i <= n; i++)
//		for (int j = i + 1; j <= n; j++)
//		{
//			if (mp[i][j] < INT_MAX) 
//				b[++tot] = {i, j, mp[i][j]};
//		}
//	for (int i = 1; i <= tot; i++) cout << b[i].x <<" " <<b[i].y << " " << b[i].w <<"\n"; 
	if (k == 0)
	{
		subK();
		return 0;
	}
	for (int i = 1; i <= k; i++)
	{
		c[i] = read();
		if (c[i] != 0) is_subA = 0;
		for (int j = 1; j <= n; j++) cc[i][j] = read();
	}
	if (is_subA)
	{
		subA();
		return 0;
	}
	return 0;
}

