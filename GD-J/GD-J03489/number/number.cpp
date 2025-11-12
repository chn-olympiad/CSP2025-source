#include <bits/stdc++.h>
using namespace std;
bool e(string a, string b)
{
	if (b < a) return true;
	return false;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, a[1000001];
	getline(cin, s);
	int l = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[l] = s[i];
			l++;
		}
	}
	sort(a, a + l, e);
	for (int i = 0; i < l; i++)
	{
		cout << a[i];
	}
	return 0;
}
