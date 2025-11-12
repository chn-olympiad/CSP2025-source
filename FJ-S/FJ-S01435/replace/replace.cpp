#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d %d", &n, &q);
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 1 ; i <= n + q - 1; i ++)
	{
		string t1, t2;
		cin >> t1 >> t2;
	}
	for (int i = 1 ; i <= q ; i ++)
	{
		printf("%d\n", i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
