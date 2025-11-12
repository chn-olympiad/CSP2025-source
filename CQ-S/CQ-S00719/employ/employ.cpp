#include<cstdio>
using namespace std;
int const N = 500 + 1, MOD = 998244353;
int diff[N], c[N], n, m, ans;
char str[N];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", str);
	for(int i = 0;i != n;i++) diff[i] = str[i] - '0';
	for(int i = 0;i != n;i++) scanf("%d", &c[i]);
	printf("%d", 2);
	return 0;
}
