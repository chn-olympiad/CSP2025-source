#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int ans = 0;
struct Club
{
	int id;
	int val;
};
vector<int> a, b, c;
void dfs(int p = 0, int x = 0, int y = 0, int z = 0, int tot = 0)
{
	if (p == n)
	{
		ans = max(ans, tot);
		//~ cerr << "[INFO] " << tot << " " << x << y << z << endl;
		return;
	}
	if (x < n / 2) dfs(p + 1, x + 1, y, z, tot + a[p]);
	if (y < n / 2) dfs(p + 1, x, y + 1, z, tot + b[p]);
	if (z < n / 2) dfs(p + 1, x, y, z + 1, tot + c[p]);
}
signed main()
{
	#ifndef DEBUG
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	#endif // DEBUG
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		ans = 0;
		cin >> n;
		a.clear();
		b.clear();
		c.clear();
		for (int i = 1; i <= n; i++)
		{
			int xx, yy, zz;
			cin >> xx >> yy >> zz;
			a.push_back(xx);
			b.push_back(yy);
			c.push_back(zz);
		}
		//~ sort(a.begin(), a.end(), cmp);
		//~ sort(b.begin(), b.end(), cmp);
		//~ sort(c.begin(), c.end(), cmp);
		dfs();
		cout << ans << endl;
	}
	cout << endl;
	return 0;
}
/* 游记：
 * t1打了半天终于看懂题目了，dfs走人，预计40~50pts，s的t1这么难？
 * t2整个没法写，算了
 * t3直接遍历 O(nq) 50pts
 * 剩下30min，t4不想写了，90pts结束，大概率2=都没qaq
 */
