#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
char c[maxn];
int a[maxn];
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> c;
	int n = strlen(c);
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			a[++num] = c[i] - '0';
		}
	}
	sort(a+1, a+1+num);
	for(int i = num; i >= 1; i--)
	{
		cout << a[i];
	}
	return 0;
}
