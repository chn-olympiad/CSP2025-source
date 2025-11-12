#include <cstdio>
#include <algorithm>
const int N = 500005, M = (1 << 21) + 5;
int a[N];
int s[N];
int last[M];
int n, k;
int f[N], g[N], Max[N];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i < (1 << 20); i++) last[i] = n + 1;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i - 1] ^ a[i];
		g[i] = last[s[i] ^ k];
		last[s[i]] = i;
//		printf("last %d = %d\n". )
	}
	for(int i = 1; i <= n; i++) {
		if(g[i] < i) f[i] = Max[g[i]] + 1;
		Max[i] = std::max(Max[i - 1], f[i]);
	}
	printf("%d\n", Max[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}