#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5 * 1e5 + 100;
int n, i, j;
ll k, a[N], xsum[N];
int dfs(int l){
	int i;
	int maxx = 0;
	for(i = l; i <= n; i ++){
		int xxor = xsum[l-1] ^ xsum[i];
		if(xxor == k){
			maxx = max(dfs(i + 1) + 1, maxx);
			break;
		}
	}
	return maxx;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%lld", &n, &k);
	for(i = 1; i <= n; i ++){
		scanf("%lld", &a[i]);
		xsum[i] = xsum[i-1] ^ a[i];
	}
	printf("%d", dfs(1));
	return 0;
}
