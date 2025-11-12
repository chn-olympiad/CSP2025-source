#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
char ch[N];
int n, a[N], tot;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", ch + 1);
	n = strlen(ch + 1);
	for (int i = 1; i <= n; i++) {
		if ('0' <= ch[i] && ch[i] <= '9') {
			a[++tot] = ch[i] - '0';
		}
	}
	sort(a + 1, a + tot + 1, greater<int>());
	if (a[1] == 0) puts("0");
	else {
		for (int i = 1; i <= tot; i++)
			printf("%d", a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}