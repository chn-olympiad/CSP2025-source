#include <bits/stdc++.h>
using namespace std;
string s, s1;
int main ()
{
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	getline (cin, s);
	int l = s.size ();
	for (int i = 0; i < l; i ++)
	{
		if (s[i] >='0' && s[i] <= '9')
			s1 = s1 + s[i];
	}
	sort (s1.begin (), s1.end ());
	int l1 = s1.size ();
	for (int i = l1 - 1; i >= 0; i --)
		cout << s1[i];
	return 0;
}
