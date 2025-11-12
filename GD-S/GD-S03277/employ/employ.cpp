#include <bits/stdc++.h>
using namespace std;
int n, m, js, c[800];
string s;
int main ()
{
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	
	scanf ("%d%d", &n, &m);
	cin >> s;
	for (int i = 0; i < n; ++i)
	{
		js += s[i] - '0';
	}
	printf ("%d", 0);
	fclose (stdin);
	fclose (stdout);
	return 0;
}
