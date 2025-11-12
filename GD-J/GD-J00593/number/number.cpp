#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int a[17];

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			int x = s[i] - 48;
			a[x]++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 0; j < a[i]; j++)
		{
			cout << i;
		}
	}
	return 0;
}
