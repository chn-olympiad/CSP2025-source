#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e2 + 5,mod = 998244353;
int s[MAXN],c[MAXN],res[MAXN],ans[MAXN];
bool flag[MAXN];
inline void dfs(int dep,int n)
{
	if (dep == n)
	{
		int no = 0,resans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (no < c[res[i]] && s[i]) resans++;
			else no++;
		}
//		for (int i = 1; i <= n; i++) cout << res[i] << ' ';
//		cout << '\n' << resans << '\n';
		ans[resans]++;
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!flag[i])
		{
			flag[i] = true;
			res[dep + 1] = i;
			dfs(dep + 1,n);
			flag[i] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long fans = 0;
	char ch;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> ch;
		s[i] = ch - '0';
	}
	for (int i = 1; i <= n; i++) cin >> c[i];
	sort(c + 1,c + n + 1);
	dfs(0,n);
	for (int i = m; i <= n; i++) fans += ans[i];
	cout << fans % mod << '\n';
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
