#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000020], cnt;
int main ()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < (int)s.length(); i ++)
		if(s[i] >= '0' && s[i] <= '9') a[cnt + 1] = (int)s[i] - '0', cnt ++;
	sort(a + 1, a + cnt + 1);
	for (int i = cnt; i >= 1; i --)
		cout << a[i];
	return 0;
}
