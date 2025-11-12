#include <bits/stdc++.h>
using namespace std;
const int maxa = (1 << 20) + 5, maxn = 5e5 + 5;
int read() {
	char e = getchar(); int o = 0;
	while(e < '0' || e > '9') e = getchar();
	while(e >= '0' && e <= '9') o = (o << 3) + (o << 1) + (e ^ 48), e = getchar();
	return o;
}
int n, k, a[maxn], p[maxa], f[maxn], l[maxn];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n = read(), k = read();
	for(int i = 1, j = (1 << 20); i < j; ++i) p[i] = -1;//p[0] = 0;
	for(int i = 1, s = 0; i <= n; ++i) {
		a[i] = read();
		s = s ^ a[i];
		l[i] = (p[s ^ k] == -1 ? 0 : p[s ^ k] + 1);
		f[i] = f[i - 1];
		if(l[i]) if(f[l[i] - 1] + 1 > f[i]) f[i] = f[l[i] - 1] + 1;
		p[s] = i;
	}
	printf("%d", f[n]);
	return 0;
}
