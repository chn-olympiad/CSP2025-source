#include <iostream>
#include <cstdio>
using namespace std;
int n, m, p[505];
char c[505];
unsigned long long ans = 1;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d %d", &n, &m);
	scanf("%s", &c);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 2; i <= n; i++) ans = (ans * i) % 998244353;
	printf("%lld", ans);
//	fclose(stdin); fclose(stdout);	
	return 0;
}
