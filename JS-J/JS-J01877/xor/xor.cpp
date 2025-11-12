#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5+5;

int n, k, a[maxn], p[1<<22], r, ans;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	memset(p, -1, sizeof(p)); p[0] = 0;
	for (int i = 1; i <= n; i++){
		scanf("%d", a+i); a[i] ^= a[i-1];
		if (p[a[i]^k] >= r){
			ans++;
			r = i;
		}p[a[i]] = i;
	}printf("%d\n", ans);
	return 0;
}
