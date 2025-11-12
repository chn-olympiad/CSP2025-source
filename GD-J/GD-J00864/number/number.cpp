#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2 * 1e6 + 10, RP = LONG_LONG_MAX;

char c;
int len, a[N];
bool quan0 = true; 

signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while (cin >> c)
	{
		if (c >= '0' and c <= '9')
		{
			if (c != '0')
				quan0 = false;
			a[++len] = c - '0';
		}
	}
	if (quan0)
		cout << 0;
	else
	{
		sort(a + 1, a + len + 1);
		for (int i = len; i >= 1; i--)
			cout << a[i];
	}
	
	return 0;
 } 
