#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
string s;
long long cnt[10];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			cnt[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		for (int j = 1; j <= cnt[i]; j++)
		{
			cout << i;
		}
	}
	return 0;
}