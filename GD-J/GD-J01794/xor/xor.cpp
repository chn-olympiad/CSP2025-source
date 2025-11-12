#include <bits/stdc++.h>
using namespace std;
const int N = 500050, M = 1<<20|9;
int n, m, i, j, k, s, f[N], p[M];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &m);
	memset(p, -1, sizeof(p));
	for(p[0]=0, i=1; i<=n; i++){
		scanf("%d", &k);
		s ^= k, f[i] = f[i-1];
		if(~p[s^m]) f[i] = max(f[i], f[p[s^m]]+1);
		p[s] = i;
	}
	printf("%d\n", f[n]);
	return 0;
}
