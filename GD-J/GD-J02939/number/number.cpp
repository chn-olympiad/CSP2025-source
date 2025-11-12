#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	string t = "";
	for (int i = 0; s[i] != '\0'; ++i)
	{
		if (isdigit(s[i]))
		{
			t += s[i];
		}
	}
	stable_sort(t.rbegin(), t.rend());
	for (int i = 0; t[i] != '\0'; ++i)
	{
		putchar(t[i]);
	}
	return 0;
}
