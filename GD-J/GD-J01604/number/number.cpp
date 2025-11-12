#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int len = 0;
	string s, j = "";
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			j += s[i];
			len++;
		}
	}
	sort(j.begin(), j.begin() + len, greater<char>());
	cout << j;
	return 0;
}
