#include <bits/stdc++.h>
using namespace std;
string s;
int n[1000005], x;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			n[x++] = s[i] - '0';
		}
	}
	sort(n, n + x + 1);
	for (int i = x; -i >= 1; i--)
	{
		cout << n[i];
	}
	return 0;
}
