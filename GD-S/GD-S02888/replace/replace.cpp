#include <bits/stdc++.h>
using namespace std;
int n, q, ans;
string t1, t2, s1[200005], s2[200005]; 
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++)
	{
		ans = 0;
		cin >> t1 >> t2;
		for (int j = 1; j <= n; j++)
		{
			string temp = t1;
			for (int k = 0; k <= t1.size() - s1[j].size() + 1; k++)
			{
				if (k + s1[j].size() > temp.size())
				{
					break;
				}
				if (temp.substr(k, s1[j].size()) == s1[j])
				{
					temp.replace(k, s1[j].size(), s2[j]);
					if (temp == t2)
					{
						ans++;
					}
					temp = t1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

2
0
*/
