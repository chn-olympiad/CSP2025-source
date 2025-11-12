#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char s[N];
int n, p[N], len;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		if (s[i] >= '0' && s[i] <= '9')
			p[++len] = s[i] - '0';
	sort(p + 1, p + len + 1);
	for (int i = len; i; i--)
		printf("%d", p[i]);	
	return 0;	
} 
