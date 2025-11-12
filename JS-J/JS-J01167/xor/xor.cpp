#include <bits/stdc++.h>
using namespace std;

int cnt[1048586];
int n, k;
int a[500060];
int qzh[500044];

void Solve2()
{
	if (k == 0)
		cout << cnt[0] + cnt[1] / 2 << endl;
	else
		cout << cnt[1] << endl;
	exit(0);
}
int ans = 0, tmp1 = 0, tmp2 = 0, tmp3 = 0;
//  2 1 0 3
// 0 2 3 3 0
void dfs(int pos, int dep, bool flag, int start)
{
	if (pos == n + 1)
	{
		ans = max(ans, dep);
		return ;
	}
	if (!flag)
	{
		dfs(tmp1 + 1, tmp2, true, tmp1 + 1);
		dfs(tmp1 + 1, tmp2, false, start);
	}
	if (flag)
	{
		bool fl = false;
		int i = 0;
		for (i = pos; i <= n; i++)
			if ((qzh[i] ^ qzh[start - 1]) == k)
			{
				fl = true;
				break;
			}
		if (fl)
		{
			tmp1 = i;
			tmp2 = dep + 1;
			return ;
		}
		else
		{
			tmp1 = pos;
			tmp2 = dep;
			ans = max(ans, dep);
			return ;
		}
	}
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cnt[a[i]]++;
	if (cnt[1] == n)
	{
		cout << n / 2 << endl;
		return 0;
	}
	if (cnt[0] + cnt[1] == n)
		Solve2();
	qzh[0] = 0;
	for (int i = 1; i <= n; i++)
		qzh[i] = (qzh[i - 1] ^ a[i - 1]);
	dfs(0, 0, false, 1);
	cout << ans << endl;
	return 0;
}
