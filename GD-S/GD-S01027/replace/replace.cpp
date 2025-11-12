#include <iostream>
#define int long long
using namespace std;
const register int N = 2e5 + 10;
string a[N], b[N], c[N];
int n, q, he[N], ba[N];
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (register int i = 1, len; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		c[i] = b[i];
		len = a[i].size();
		for (register int j = 0; j < len; ++j)
			if (a[i][j] == b[i][j])
				c[i][j] = ' ';
		while (he[i] < len && c[i][he[i]] == ' ')
			++he[i];
		ba[i] = len - 1;
		while (ba[i] >= 0 && c[i][ba[i]] == ' ')
			--ba[i];
	}
	while (q--)
	{
		register string t1, t2, tmp;
		cin >> t1 >> t2;
		register int len = t1.size(), ans = 0;
		if (len != t2.size())
		{
			cout << "0\n";
			continue;
		}
		tmp = t2;
		for (register int i = 0; i < len; ++i)
			if (t1[i] == t2[i])
				tmp[i] = ' ';
		register int head = 0, back = len - 1;
		while (head < len && tmp[head] == ' ')
			++head;
		while (back >= 0 && tmp[back] == ' ')
			--back;
		for (register int i = 1; i <= n; ++i)
		{
			if (t1 != a[i] && (int)t1.find(a[i]) == -1)
				continue;
			if (back - head != ba[i] - he[i])
				continue;
			register bool flag = 1;
			for (register int j = head, k = he[i]; j <= back && k <= ba[i]; ++j, ++k)
			{
				if (tmp[j] != c[i][k])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
				++ans;
		}
		cout << ans << '\n';
	}
	return 0;
}
