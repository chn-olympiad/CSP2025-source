#include <bits/stdc++.h>

using namespace std;

int nb[10] = {};

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	for (int i = 0;i < s.size();i++)
	{
		if (s[i] >= '0' and s[i] <= '9')
		{
			nb[(s[i] - '0')]++;
		}
	}
	for (int i = 9;i >= 0;i--)
	{
		for (int j = 0;j < nb[i];j++)
		{
			cout << i;
		}
	}
	return 0;
}
