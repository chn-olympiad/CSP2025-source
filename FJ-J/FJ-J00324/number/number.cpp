#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;
int n, a[N], sz;
char c[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", c + 1); n = strlen(c + 1);
	for (int i = 1; i <= n; i++)
		if ('0' <= c[i] && c[i] <= '9')
			a[++sz] = c[i] - '0';
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= sz; i++)
		printf("%d", a[i]);
	return 0;
}

