#include<cstdio>

using namespace std;

const int N = 10005;

int n, k;
int a[N];
int res;
void dfs(int x, int st, int q) { 
	
	if(st > n) {
		if(res < q) res = q;
		return;
	}
	
	for(int i = st; i <= n;i++) {
		x ^= a[i];
		if(x == k) {
			dfs(0, i+1, q+1);
			break;
		}
	}
	return;
}

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) {
		scanf("%d", &a[i]); 
	}
	dfs(0, 1, 0);
	printf("%d", res);
	return 0;
}