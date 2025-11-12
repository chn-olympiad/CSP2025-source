#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;

string s;

int a[N];

bool cmp (const int &a, const int &b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	int n = s.size();

	int len = 0;
	for (int i = 0; i < n; i++)
		if ('0' <= s[i] && s[i] <= '9')
		{
			a[++len] = s[i] - '0';
		}

	sort(a + 1, a + len + 1, cmp);

	if (a[1] == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i <= len; i++)
		cout << a[i];
	cout << endl;

	return 0;
}
