#include <bits/stdc++.h> 
using namespace std;
int a[1000005];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int cur = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		if ('0' <= s[i] and s[i] <= '9') a[++cur] = s[i] - '0';
	sort(a + 1, a + cur + 1, cmp);
	for (int i = 1; i <= cur; i++)
		cout << a[i];
	return 0;
}
