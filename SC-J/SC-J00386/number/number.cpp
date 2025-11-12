#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[1000010];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	string s;
	cin >> s;
	int cur = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			a[++cur] = s[i] - '0';
		}
	}
	sort(a + 1, a + cur + 1, cmp);
	for (int i = 1; i <= cur; i++)
	{
		cout << a[i];
	}
	return 0;
}