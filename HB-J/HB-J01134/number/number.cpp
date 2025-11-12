#include <bits/stdc++.h>
using namespace std;

string s, t;
int a[1000005], st;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	bool all_0 = 1;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[++st] = s[i] - 48;
			if (s[i] != '0')
				all_0 = 0;
		}
	}
	if (all_0)
	{
		cout << 0 << endl;
		return 0;
	}
	sort(a + 1, a + st + 1, cmp);
	for (int i = 1; i <= st; i++)
		cout << a[i];
	cout << endl;
	return 0;
}
