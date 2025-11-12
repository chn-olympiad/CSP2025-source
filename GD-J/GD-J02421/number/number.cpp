#include <iostream>
#include <string>
#include <algorithm>
#define int long long
using namespace std;
string s;
const int MAXN = 1e6 + 6;
int s1[MAXN];

signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int j = 0;
	for (int i = 0; i <= s.length(); i++)
	{
		if (s[i] >= 48 && s[i] <= 58)
		{
			s1[j] = s[i] - 48;
			j++;
		}
	}
	sort(s1, s1 + j);
	j -= 1;
	for (; j >= 0; j--)
	{
		cout << s1[j];
	}
	cout << endl;
	return 0;
}
