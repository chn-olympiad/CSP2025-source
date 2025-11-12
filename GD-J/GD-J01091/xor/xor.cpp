#include<bits/stdc++.h>
using namespace std;
#define N 500050
int n, m, i, j, k, f[N], a[N];
map <int, int> s;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++) scanf("%d", &a[i]), a[i] ^= a[i-1];
	for (f[0]=s[0]=i=1; i<=n; i++) {
		f[i] = f[i-1];
		if (s[m^a[i]]) f[i] = max(f[i], s[m^a[i]]+1);
		s[a[i]] = f[i];
	}
	printf("%d", f[n]-1);
	return 0;
}

