#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
char s[N], ans[N];
int n, tot = 0;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		if (isdigit(s[i]))
			ans[tot++] = s[i];
	sort(ans, ans + tot);
	reverse(ans, ans + tot);
	printf("%s", ans);
	return 0;
}