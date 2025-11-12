#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, t = "";
	int cnt = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if(('0' <= s[i]) && (s[i] <= '9'))
		{
			t += s[i];
			cnt++;
		}
	}
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < cnt - 1; j++)
			if(t[j] < t[j + 1])
				swap(t[j], t[j + 1]);
	}
	cout << t;
	return 0;
}