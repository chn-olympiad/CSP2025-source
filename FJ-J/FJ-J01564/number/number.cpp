#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
bool comp(pii a, pii b)
{
	return a.first > b.first;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s; cin >> s;
	int mem[10] = {};
	int len = s.length();
	for (int i = 0; i < len; ++i)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			++mem[s[i] - '0'];
		}
	}
	for (int i = 9; i >= 0; --i)
	{
		for (int j = 0; j < mem[i]; ++j)
		{
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
