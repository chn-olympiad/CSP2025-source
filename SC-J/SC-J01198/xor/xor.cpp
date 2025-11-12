#include<bits/stdc++.h>
//#undef STDIO
const int N = 5e5 + 10, M = (1 << 21) + 10;
int f[N], g[M], a[N], s[N], n, k, ans;
int main(){
#ifndef STDIO
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		s[i] = a[i] ^ s[i - 1]; 
	}
	memset(g, 0xcf, sizeof g);
	g[0] = 0;
	for(int i = 1; i <= n; i++){
		f[i] = f[i - 1];
		if(g[k ^ s[i]] >= 0) f[i] = std::max(f[i], g[k ^ s[i]] + 1);
		g[s[i]] = std::max(g[s[i]], f[i]);
		ans = std::max(ans, f[i]);
	}
	printf("%d\n", ans);
	fflush(stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}