#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

const int N = 1e6 + 7;

int tot, n, buk[11];

using namespace std;

string s;

int main ()
{
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	ios :: sync_with_stdio (NULL);
	cin.tie (NULL);
	cout.tie (NULL);
	cin >> s;
	n = s.size ();
	for (int i = 0; i < n; i ++)
		if ('0' <= s[i] && s[i] <= '9')
			buk[s[i] - '0'] ++;
	for (int i = 9; i >= 0; i --)
		for (int j = 1; j <= buk[i]; j ++)
			cout << i;
}
