#include<bits/stdc++.h>
using namespace std;
long long a[500010], pre[500010], num[500010], f[500010][2];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	memset(num, 0x3f, sizeof(num));
	num[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		pre[i] = pre[i - 1] ^ a[i];
		int pos = num[pre[i] ^ k];
		if(pos < i) {
			f[i][1] = max(f[pos][0], f[pos][1]) + 1; 
		}
		f[i][0] = max(f[i - 1][0], f[i - 1][1]);
		num[pre[i]] = i;
	}
	printf("%lld", max(f[n][0], f[n][1]));
	return 0;
}
