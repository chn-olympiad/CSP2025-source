#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	vector<string> a, b;
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++)
	{
		string x, y;
		cin >> x >> y;
		a.push_back(x);
		b.push_back(y);
	}
	for (int i = 1; i <= q; i ++)
	{
		string x, y;
		cin >> x >> y;
		int ans = 0;
		for (int j = 0; j < x.length(); j ++)
		{
			for (int k = j; k < x.length(); k ++)
			{
				string x1 = x;
				string tmp = "";
				for (int l = j; l <= k; l ++)
				{
					tmp += x1[l];	
				}
				if (find(a.begin(), a.end(), tmp) != a.end())
				{
					for (int l = j; l <= k; l ++)
					{
						x1[l] = b[find(a.begin(), a.end(), tmp) - a.begin()][l - j];
					}
					if (x1 == y)
					{
						ans ++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}