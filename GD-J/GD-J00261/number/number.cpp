#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int num = 0;
	int maxx = -1;
	int numofzero = 0;
	for (int i = 0;i < s.length();i ++)
	{
		if (s[i] > '9')
			s[i] = 'd';
	}
	int a[190000] = {};
	for (int i = 0;i < s.length();i ++)
	{
		if (s[i] - '0' == 0)
			numofzero ++;
		if(s[i] != 'd')
			a[i] = s[i] - '0';
	}
	sort(a, a + s.length());
	for (int i = s.length() - 1;i >= 0;i --)
	{
		if (a[i] == 0)
			break;
		cout << a[i];
	}
	for (int i = 0;i < numofzero;i ++)
		cout << 0;
	return 0;
}
