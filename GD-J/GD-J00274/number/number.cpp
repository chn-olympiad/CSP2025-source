#include <bits/stdc++.h>
using namespace std;

int x[1000010];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int cnt = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			x[++cnt] = s[i] - '0';
		}
	}
	sort(x + 1, x + cnt + 1);
	for (int i = cnt; i >= 1; i--) cout << x[i];
	return 0;
} 
