#include <bits/stdc++.h>
using namespace std;
int suiji() {
	int n = rand() % 15;
	if (n < 12) puts("0");
	else printf("%d\n", rand() % 10);
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	srand(time(0));
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; i++) suiji();
	return 0;
}
