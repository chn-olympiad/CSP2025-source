#include <bits/stdc++.h>
using namespace std;

struct Miao
{
	string s1, s2;
}a[5000007];

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].s1 >> a[i].s2;
	}
	while (q--)
	{
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size())
		{
			cout << 0;
		}
		else
		{
			int cnt = 0;
			for (int i = 0; i < t1.size(); i++)
			{
				for (int j = i; j < t2.size(); j++)
				{
					string r1 = t1.substr(i, j - i + 1), r2 = t2.substr(i, j - i + 1);
					if (t1.substr(0, i) == t2.substr(0, i) && t1.substr(j + 1) == t2.substr(j + 1))
					{
						for (int k = 0; k < n; k++)
						{
							if (r1 == a[k].s1 && r2 == a[k].s2) cnt++;
						}
					}
				}
			}
			cout << cnt;
		}
		cout << endl;
	}
	return 0;
}
