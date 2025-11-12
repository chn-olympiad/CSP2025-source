#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

char s[N];
int cnt[20];

void solve()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1), tot = 0;
	for (int i = 1; i <= n; i ++ )
	{
		if ('0' <= s[i] && s[i] <= '9') cnt[s[i] - '0'] ++ ;
	}
	for (int i = 9; ~i; i -- )
		while (cnt[i] -- )
			putchar(i + '0');
	putchar('\n');
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int T = 1;
	while (T -- ) solve();
	return 0;
}
