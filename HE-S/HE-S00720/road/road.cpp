#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int cnt, n, m, k, fa[N], ans;
struct Node
{
	int a, b, c;
}e[N];
bool cmp(Node a, Node b)
{
	return a.c < b.c;
}
int find(int x)
{
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	int num = n;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++)
		cin >> e[i].a >> e[i].b >> e[i].c;
	for(int i = n + 1, s; i <= n + 1 + k; i++)
	{
		cin >> s;
		for(int j = 1, a1; j <= n; j++)
			cin >> a1, e[i + j].a = i, e[i + j].b = j, e[i + j].c = s + a1;
	}
	sort(e + 1, e + 1 + n + k, cmp);
	for(int i = 1; i <= n + k; i++)
	{
		int x = find(e[i].a), y = find(e[i].b);
		if(x != y)
		{
			if(e[i].a <= n) num--;
			fa[x] = y, ans += e[i].c;
		}
		if(++cnt == n - 1 && num <= 0) return cout << ans, 0;
	}
	return cout << ans, 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
