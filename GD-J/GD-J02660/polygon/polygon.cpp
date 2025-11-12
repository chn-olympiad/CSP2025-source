#include <iostream>
#include <map>
using namespace std;
int n, l[25];
int tag[25];
int ans;
map<int, int> mp;
void dfs(int dep, int sum, int Mx, int t, int id)
{
	if (t >= 3 && dep <= n + 1)
		if (sum > 2 * Mx && (!mp[id]))
		{
			ans++;
			mp[id] = 1;
//			for (int i = 1; i <= n; i++)
//				cout << tag[i] << ' ';
//			cout << '\n';
		}
	if (dep >= n + 1)
		return;
	tag[dep] = 1;
	dfs(dep + 1, sum + l[dep], max(Mx, l[dep]), t + 1, (id | (1 << (dep - 1))));
	tag[dep] = 0;
	dfs(dep + 1, sum, Mx, t, id);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> l[i];
	dfs(1, 0, 0, 0, 0);
	cout << ans;
}
