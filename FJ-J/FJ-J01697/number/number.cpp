#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int d[N], n, cnt;

string str;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> str;
	n = str.size();
	for (int i = 0; i < n; i++)
	{
		if ('0' <= str[i] && str[i] <= '9')
		{
			d[++cnt] = (str[i] - '0');
		}
	}
	sort(d + 1, d + 1 + cnt, greater<int>());
	for (int i = 1; i <= cnt; i++)
	{
		printf("%d", d[i]);
	}
	return 0;
}
