#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int len, tot = 0, num[N];
char s[N];
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	len = strlen(s + 1);
	for(int i = 1; i <= len; ++i)
	{
		if(s[i] >= '0' && s[i] <= '9') num[++tot] = s[i] - '0';
	}
	sort(num + 1, num + tot + 1, cmp);
	for(int i = 1; i <= tot; ++i) printf("%d", num[i]);
	return 0;
}
