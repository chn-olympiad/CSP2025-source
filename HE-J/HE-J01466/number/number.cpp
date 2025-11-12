#include <bits/stdc++.h>
using namespace std;
int a[20], n;
bool f = 1; 
string s;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s, n = s.length();
	for (int i = 0; i < n; i ++)
		if (s[i] >= '0' && s[i] <= '9')
			a[s[i] - '0'] ++;
	for (int i = 9; i > 0; i --)
	{
		if (a[i])
			f = 0;
		while (a[i] --)
			cout << i;
	}
	if (f)
		cout << 0;
	else
		while (a[0] --)
			cout << 0;
	return 0;
}
