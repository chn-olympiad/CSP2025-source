#include <bits/stdc++.h>
using namespace std;
const int A = 2e5 + 10;
string s1[A], s2[A], t1, t2;
int a[A], n, q;
bool f;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++)
		cin >> s1[i] >> s2[i];
	cin >> t1 >> t2;
	for (int i = 1; i <= n; i ++)
	{
		f = 1;
		if (s1[i].length() != s2[i].length())
			cout << "0\n";
		for (int k = 0, l = s1[i].length(), m = t1.length(); k + m <= l; k ++)
			if (s1[i].substr(k, m) == t1 && s2[i].substr(k, m) == t2 && s1[i].substr(0, k) == s2[i].substr(0, k) && s1[i].substr(k + m, l - k - m) == s2[i].substr(k + m, l - k - m))
				cout << "1\n", f = 0;
		if (f)
			cout << "0\n";
	}
	return 0;
}
