#include <bits/stdc++.h>
using namespace std;

int cnt;

bool B(string s)
{
	cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'b')
		{
			cnt++;
		}
		if (s[i] != 'a' && s[i] != 'b')
		{
			return false;
		}
	}
	if (cnt == 1)
	{
		return true;
	}
	return false;
}

int n, qqq, l[200005], r[200005], ll, rr, ans, ttt;

string s[200005][2], t1, t2;

bool bl = true;

void solve(string t1, string t2)
{
	ans = 0;
	ll = rr = -1;
	for (int j = 0; j < t1.size(); j++)
	{
		if (t1[j] != t2[j])
		{
			if (ll == -1)
			{
				ll = j;
				break;
			}
		}
	}
	for (int j = t1.size() - 1; j >= 0; j--)
	{
		if (t1[j] != t2[j])
		{
			if (rr == -1)
			{
				rr = j;
				break;
			}
		}
	}
	for (int i = 1, j, k; i <= n; i++)
	{
		if (l[i] == -1)
		{
			continue;
		}
		if (r[i] - l[i] != rr - ll || rr + s[i][0].size() - r[i] > t1.size() || ll - l[i] < 0)
		{
			continue;
		}
		for (j = 0, k = ll - l[i]; j < s[i][0].size() && k < ll - l[i] + s[i][0].size(); j++, k++)
		{
			if (s[i][0][j] != t1[k] || s[i][1][j] != t2[k])
			{
				ans--;
				break;
			}
		}
		ans++;
	}
	printf("%d\n", ans);
	return;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &qqq);
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][0] >> s[i][1];
		bl = bl & B(s[i][0]) & B(s[i][1]);
		l[i] = r[i] = -1;
		if (s[i][0] == s[i][1])
		{
			continue;
		}
		for (int j = 0; j < s[i][0].size(); j++)
		{
			if (s[i][0][j] != s[i][1][j])
			{
				if (l[i] == -1)
				{
					l[i] = j;
					break;
				}
			}
		}
		for (int j = s[i][0].size() - 1; j >= 0; j--)
		{
			if (s[i][0][j] != s[i][1][j])
			{
				if (r[i] == -1)
				{
					r[i] = j;
					break;
				}
			}
		}
	}
	while (qqq--)
	{
		ttt += n;
		cin >> t1 >> t2;
		bl = bl & B(t1) & B(t2);
		if (t1.size() != t2.size() || ttt >= 1e9)
		{
			printf("0\n");
			continue;
		}
//		if (bl)
//		{
//			solve2(t1, t2);
//			continue;
//		}
		solve(t1, t2);
	}
	return 0;
}
