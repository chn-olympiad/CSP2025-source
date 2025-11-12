#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int a, b, c;
	scanf("%d%d%d%d", &a, &a, &b, &c);
	if (a + b + c > (max(a, max(b, c)) << 1)) putchar('1');
	else putchar('0');
	return 0;
}
