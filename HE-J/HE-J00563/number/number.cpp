#include <bits/stdc++.h>

using namespace std;

const int N = 10e6 + 10;
char s[N];
int a[N], l = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	int n = (int)strlen(s + 1);
	for (int i = 1; i <= n; i++)
		if ('0' <= s[i] && s[i] <= '9')
			a[++l] = (int)(s[i] - '0');
	sort(a + 1 , a + l + 1);
	for (int i = l; i >= 1; i--)
		printf("%d", a[i]);
	puts("");
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
