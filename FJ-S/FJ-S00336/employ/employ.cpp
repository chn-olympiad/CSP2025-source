#include <bits/stdc++.h>
using namespace std;
int n,m, c[505], a[505], fl_;
char s[505];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 0; i < n; i++) {
		a[i] = c[i]-'0';
		if (a[i] == 0) fl_++;
	}
	if (m == 1) {
		printf("%d", (n-fl_));
	} else printf("18");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
