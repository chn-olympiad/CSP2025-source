#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;

char c[N];

int a[N];

int n, cnt;

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", c + 1);
	int n = strlen(c + 1);
	
	for (int i = 1; i <= n; ++i) {
		if (c[i] >= '0' && c[i] <= '9')
			a[++cnt] = c[i] - '0';
	}
	
	sort(a + 1, a + 1 + cnt);
	
	if (a[cnt] == 0)
		return printf("0"), 0;
		
	for (int i = cnt; i; --i)
		printf("%d", a[i]);
		
	return 0;
}
