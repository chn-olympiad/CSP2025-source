#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	string s;
	cin >> s;
	int len = s.size(); int k = 0;
	for (int i=0; i<=len-1; i++)
		if (s[i] >= '0' && s[i] <= '9') k++, a[k] = (s[i] - '0');
	sort (a + 1, a + 1 + k);
	for (int i=k; i>=1; i--)
		printf ("%d", a[i]);
	printf ("\n");
	return 0;
}
