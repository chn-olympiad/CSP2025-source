#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int ans;
string s;
int c[15];
int p[15];
int tag[15];
void dfs(int dep)
{
	if (dep == n + 1)
	{
		int cnt = 0, cnt2 = 0;
		for (int i = 1; i <= n; i++)
		{
//			cout << p[i];
			if (cnt >= c[p[i]])
				cnt++;
			else
			{
				if (s[i - 1] == '0')
					cnt++;
				else
					cnt2++;
			}
		}
		if (cnt2 >= m)
			ans++;
		return;
	}
	for (int i = dep; i <= n; i++)
		swap(p[dep], p[i]), dfs(dep + 1), swap(p[dep], p[i]);
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		p[i] = i;
	}
	dfs(1);
	cout << ans;
}
