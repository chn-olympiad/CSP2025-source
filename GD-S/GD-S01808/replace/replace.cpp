#include <bits/stdc++.h>
using namespace std;
long long n, q, num[200005][3], numt[200005][3];
string s[200005][3], t[3];
bool flag = 1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++)
	{
		cin >> s[i][1] >> s[i][2];
		if (!flag)
			continue;
		for (int j = 0; s[i][1][j] != '\0'; j ++)
		{
			if ((s[i][1][j] != 'a' && s[i][1][j] != 'b') || (s[i][2][j] != 'a' && s[i][2][j] != 'b'))
			{
				flag = 0;
				break;
			}
			if (s[i][1][j] == 'b')
			{
				if (num[i][1])
				{
					flag = 0;
					break;
				}
				num[i][1] = j;
			}
			if (s[i][2][j] == 'b')
			{
				if (num[i][2])
				{
					flag = 0;
					break;
				}
				num[i][2] = j;
			}
		}
	}
	for (int qq = 1; qq <= q; qq ++)
	{
		long long ans = 0;
		cin >> t[1] >> t[2];
		if (t[1].length() != t[2].length())
		{
			cout << "0\n";
			continue;
		}
		if (flag)
		{
			for (int j = 0; t[1][j] != '\0'; j ++)
			{
				if ((t[1][j] != 'a' && t[1][j] != 'b') || (t[2][j] != 'a' && t[2][j] != 'b'))
				{
					flag = 0;
					break;
				}
				if (t[1][j] == 'b')
				{
					if (numt[qq][1])
					{
						flag = 0;
						break;
					}
					numt[qq][1] = j;
				}
				if (t[2][j] == 'b')
				{
					if (numt[qq][2])
					{
						flag = 0;
						break;
					}
					numt[qq][2] = j;
				}
			}
		}
		if (flag)
		{
			for (int j = 1; j <= n; j ++)
				if (numt[qq][2] - numt[qq][1] == num[j][2] - num[j][1] && numt[qq][2] >= num[j][2] && numt[qq][1] >= num[j][1] && t[2].length() - numt[qq][2] >= s[j][2].length() - num[j][2] && t[1].length() - numt[qq][1] >= s[j][1].length() - num[j][1])
					ans ++;
		}
		else
		{
			for (int j = 1; j <= n; j ++)
				for (int i = 0; t[1][i + s[j][1].length() - 1] != '\0'; i ++)
					if (t[1].substr(i, s[j][1].length()) == s[j][1])
						if (t[1].substr(0, i) + s[j][2] + t[1].substr(i + s[j][1].length()) == t[2])
						{
							ans ++;
							break;
						}
		}
		cout << ans << "\n";
	}
	return 0;
}
