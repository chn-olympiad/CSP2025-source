#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const long long N = 1e6;
long long a[N + 5], len, n;
string s;
bool cmp (int b, int c)
{
	return b > c;
}
int main ()
{
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> s;
	len = s.size ();
	for (int i = 0; i < len; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[n++] = s[i] - '0';
		}
	}
	sort (a, a + n, cmp);
	for (int i = 0; i < n; ++i)
	{
		cout << a[i];
	}
	return 0;
} 