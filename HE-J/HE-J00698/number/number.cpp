#include<bits/stdc++.h>
#define int long long

using namespace std;

int sum, b;
int a[1000010];
string s;

bool cmp(int x, int y)
{
	return x > y;
}

signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i ++)
	{
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
		{
			sum ++;
			a[b ++] = (int)s[i] - '0';
		}
	}
	sort (a, a + sum, cmp);
	for (int i = 0; i < sum; i ++)
	{
		cout << a[i];
	}
	return 0;
}
