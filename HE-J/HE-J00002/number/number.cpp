#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
string s;
int a[N], cur;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (char c: s)
		if (isdigit(c))
			a[++cur] = c - '0';
	sort(a + 1, a + cur + 1, greater<int>());
	for (int i = 1; i <= cur; i++)
		cout << a[i];
	return 0;
}
