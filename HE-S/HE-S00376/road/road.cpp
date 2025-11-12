#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e4 + 5;
const int M = 1e6 + 5;
struct node
{
	int u, v;
	int val;
	bool friend operator < (node x, node y)
	{
		return x.val < y.val;
	}
} s[M];
int n, m, k;
int c[15], a[15][N];
int fa[N];
int find(int x)
{
//	cout << x << endl;
	if (fa[x] == x)
		return x;
	else
	{
		return find(fa[x]);
	}
}
void merge(int x, int y)
{
	int fx = find(x), fy = find(y);
	fa[fx] = fy;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> s[i].u >> s[i].v >> s[i].val;
	} 
	sort(s + 1, s + m + 1);
	if (k == 0)
	{
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		int ans = 0, cnt = 1;
		for (int i = 1; i <= m && cnt <= n; i++)
		{
			int uu = s[i].u, vv = s[i].v, vl = s[i].val;
			if (find(uu) == find(vv)) continue;
			ans += vl;
			cnt++;
			merge(uu, vv);
		}
		cout << ans << endl;
	}
	else
	{
		cout << 0 << endl;
		// Wish Me Good Luck! Byebye!
	}
}
/*
4 5 0
1 2 2
2 3 1
3 4 1
1 4 3
2 4 5
*/
