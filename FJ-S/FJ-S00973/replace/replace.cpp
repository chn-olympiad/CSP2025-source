#include <bits/stdc++.h>
using namespace std;
int n, q;
string s[200005][5], t1, t2;
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i][1] >> s[i][2];
	}
	while (q--)
	{
		cin >> t1 >> t2;
	}
	return 0;
}
