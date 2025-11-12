#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int K = 21;
const int MAXN = 2e6 + N;

int n, k, ans;
int a[N], p[N], f[N], c[MAXN];
bool flag[MAXN];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	p[0] = 0;
	for(int j = 0; j < 21; j++) {
		int t = 0;
		for(int i = 1; i <= n; i++) {
			if(a[i] & (1 << j)) t++;
			p[i] = (t & 1 ? p[i] + (1 << j) : p[i]);
		}
	}
	c[0] = 0;
	flag[0] = 1;
	for(int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		int need = k ^ p[i];
		if(flag[need])
		f[i] = max(f[i], f[c[need]] + 1);
		c[p[i]] = i;
		flag[p[i]] = 1;
	}
	for(int i = 1; i <= n; i++) {
		ans = max(ans, f[i]);
	}
	printf("%d", ans);
}