#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int maxm = 1e6 + 5;
int n, m, k;
int fa[maxn];
int findd(int x)
{
	if(x != fa[x])
		fa[x] = findd(fa[x]);
	return fa[x];
}
struct Node{
	int u, v, w;
}a[maxn];
struct node{
	int jian;
	int lian[maxn];
}b[15];
inline bool cmp(Node x, Node y)
{
	return x.w < y.w;
}
inline void bing(int x, int y)
{
	int r1 = findd(x);
	int r2 = findd(y);
	fa[r1] = r2;
}
inline int kruaskal()
{
	int cnt = 0;
	int dis = 0;
	for(int i = 1; i <= m; i++)
	{
		int r1 = findd(a[i].u);
		int r2 = findd(a[i].v);
		if(r1 != r2)
		{
			bing(r1, r2);
			cnt++;
			dis += a[i].w;
		}
		if(cnt == n - 1)
		{
			return dis;
			break;
		}
	}
	return dis;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		fa[i] = i;
	for(int i = 1; i <= m; i++)
		cin >> a[i].u >> a[i].v >> a[i].w;
	int minn = INT_MAX;
	for(int i = 1; i <= k; i++)
	{
		cin >> b[i].jian;
		minn = min(minn, b[i].jian);
		for(int j = 1; j <= n; j++)
			cin >> b[i].lian[j];
	}
	sort(a + 1, a + 1 + m, cmp);
//	for(int i = 1; i <= m; i++)
//		cout << a[i].u << ' ' << a[i].v << ' ' << a[i].w << endl;
	cout << min(minn, kruaskal());
	return 0;
}
/*
4 6
1 2 2
1 3 3
1 4 4
3 4 1
2 3 5
2 4 6
*/
