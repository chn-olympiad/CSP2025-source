#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
inline int read()
{
	int x, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
}
inline void write(int x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
const int N = 1e6 + 10;
string s;
int num[N];
int cnt;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i < len; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num[++cnt] =  s[i] - '0';
		}
	}
	sort(num + 1, num + cnt + 1, greater<int>());
	for (int i = 1; i <= cnt; ++i)
	{
		write(num[i]);
	}
	return 0;
}