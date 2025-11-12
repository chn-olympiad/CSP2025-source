#include <bits/stdc++.h>
using namespace std;
int a[1000005], l, len = 0;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	l = s.length();
	for(int i = 0; i < l; i++)
	{
		if (s[i] >= '0' && s[i] <='9')
		{
			a[++len] = s[i] - '0';
		}
	}
	sort(a + 1, a + len + 1, cmp);
	for (int i  = 1; i <= len; i++)
	{
		cout << a[i];
	}
}
