#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

string str;

int ans[N], pos, bjt;

bool cmp (int x, int y)
{
	return x > y;
}

int main ()
{
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	getline (cin, str);
	for (int i = 0;i < str.size ();i ++)
	{
		if (isdigit (str[i]))
		{
			ans[++ pos] = str[i] - '0';
			if (str[i] != '0')
			{
				bjt = 1;
			} 
		}
	}
	if (!bjt)
	{
		cout << 0;
		return 0;
	}
	sort (ans + 1, ans + pos + 1, cmp);
	for (int i = 1;i <= pos;i ++)
	{
		cout << ans[i];
	}
	return 0;
}
