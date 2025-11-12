#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m;
char s[MAXN];
int a[MAXN];
bool cmp(int x, int y)
{
	return x > y;
}
signed main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for ( int i = 1; i <= n; i++ )
	{
		if ( s[i] >= '0' && s[i] <= '9' )
		{
			a[++m] = s[i] - '0';
		}
	}
	sort(a + 1, a + m + 1, cmp);
	for ( int i = 1; i <= m; i++ )
	{
		cout << a[i];
	}
	return 0;
}
