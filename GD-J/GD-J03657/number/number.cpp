#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	char c;
	while (cin >> c)
	{
		if ('0' <= c && c <= '9')
		{
			cnt[c - '0']++;
		}
	}
	bool out = false;
	for (int i = 9; i >= 0; i--)
	{
		if (i == 0 && out == false && cnt[i])
		{
			cout << 0;
			break;
		}
		while (cnt[i]--)
		{
			cout << i;
			out = true;
		}
	}
	return 0;
}
