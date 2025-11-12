#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
string s;
int n;
int a[N];
bool cmp(int A, int B)
{
	return A > B;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			a[++n] = s[i] - '0';
		}
	}
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n; i++)
	{
		printf("%d", a[i]);
	}
	return 0;
}
