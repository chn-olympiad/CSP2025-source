#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int d[N];
int main()
{
	ios::sync_with_stdio(false);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int j = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			d[++j] = s[i] - '0';
	}
	sort(d + 1, d + j + 1, greater<int>());
	if (d[1] == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= j; i++)
		cout << d[i];
	cout << endl;
	return 0;
}
