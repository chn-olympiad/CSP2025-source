#include <bits/stdc++.h>

using namespace std;

int a[10];

int main(void)
{
	freopen("number.in", "w", stdin);
	freopen("number.out ", "r", stdout);
	string s;
	cin >> s;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] <= '9' && s[i] >= '0')
		{
			a[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < a[i]; j++)
		{
			cout << (char)(i + '0');
		}
	}
	return 0;
}
