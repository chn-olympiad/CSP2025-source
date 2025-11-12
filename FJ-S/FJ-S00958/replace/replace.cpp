#include <bits/stdc++.h>
using namespace std;

int n, q, cnt = 0; string s[200005][3];

void dfs(string a, string b)
{
	if (a == b)
	{
		cnt ++;
		return;
	}
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 0; j < a.size(); j ++)
		{
			for (int k = i; k < a.size(); k ++)
				if (a.substr(j, k - j + 1) == s[i][1])
					dfs(a.substr(0, j) + s[i][2] + a.substr(k + 1, a.size() - (k + 1)), b);
		}
	}
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) cin >> s[i][1] >> s[i][2];
	for (int i = 1; i <= q; i ++)
	{
		cnt = 0;
		string a, b;
		cin >> a >> b;
		dfs(a, b);
		cout << cnt << endl;
	}
}
