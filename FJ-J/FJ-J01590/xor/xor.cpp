#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, k, a[500005], maxn[1100005], s[500005], f[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] ^ a[i];
	memset(maxn, -1, sizeof(maxn));
	maxn[0] = 0; 
	for(int i = 1; i <= n; i++) {
		int p = s[i] ^ k;
//		cout << i << " " << p << endl;
		f[i] = f[i - 1];
		f[i] = max(f[i], maxn[p] + 1);
		maxn[s[i]] = max(maxn[s[i]], f[i]);
	}
//	for(int i = 1; i <= n; i++) cout << f[i] << " ";
	printf("%d", f[n]);
}
