#include <iostream>
#include <cstring>
using namespace std;
string s[200005][5];
int n, q, ans;
string t1, t2;
//bool check(string s1, int pos, string tar)
//{
//	int len1 = s1.length(), len2 = tar.length();
//	if (pos + len2 > len1)
//		return 0;
//	for (int i = pos, j = 0; i <= pos + len2; i++, j++)
//	{
//		if (s1[i] != tar[j])
//			return 0;
//	}
//	return 1;
//}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i][1] >> s[i][2];
	}
	while (q--)
	{
		cin >> t1 >> t2;
		ans = 0;
		int len1 = t1.size(), len2 = t2.size();
		if (len1 != len2)
		{
			cout << 0 << '\n';
			continue;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < len1; j++)
			{
				if (t1[j] == s[i][1][0])
				{
					int len3 = s[i][1].length();
					if (j + len3 > len1)
						break;
					bool flag = 1;
					for (int k = j, l = 0; k < j + len3; k++, l++)
					{
						if (t1[k] != s[i][1][l])
						{
							flag = 0;
							break;
						}
					}
					string temp = t1;
					if (flag)
					{
						for (int k = j, l = 0; k < j + len3; k++, l++)
						{
							temp[k] = s[i][2][l];
						}
						if (temp == t2)
							ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
