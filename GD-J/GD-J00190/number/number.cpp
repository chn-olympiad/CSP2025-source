#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int cnt[N];
signed main ()
{
	freopen ("number.in" , "r" , stdin);
	freopen ("number.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0) , cout.tie (0);
	string s;
	cin >> s;
	int n = s.size ();
	for (int i = 0;i < n;i ++)
	{
		char c = s[i];
		if (c < '0' || c > '9') continue;
		cnt[c - '0'] ++;
	}
	for (int i = 9;i >= 0;i --)
	{
		while (cnt[i] --) cout << i;
	}
	return 0;
}
