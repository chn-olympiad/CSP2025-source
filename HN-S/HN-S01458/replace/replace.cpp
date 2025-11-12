#include <algorithm>
#include <iostream>
#include <cstdio>
#include <array>
#include <cstring>

namespace Fujiwara
{
using std::cin;
using std::sort;
using std::string;
using ll = long long;

int n, q;
string s[105][2];
static int Azusa()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
		cin >> s[i][0] >> s[i][1];
	for (int i = 1; i <= q; ++i)
	{
		int cnt = 0;
		string a, b;
		cin >> a >> b;
		for (int j = 1; j <= n; ++j)
		{
			int p = a.find(s[j][0]);
			if (p != -1)
			{
				string tmp = a;
				for (int k = p; k <= p + s[j][1].size() - 1; ++k)
					tmp[k] = s[j][1][k - p];
				if (tmp == b)
					++cnt;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	return Fujiwara::Azusa();
}