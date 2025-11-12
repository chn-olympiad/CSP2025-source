#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
string s;
int cnt[100];
int main()
{
	freopen("number4.in.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; i++)
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
