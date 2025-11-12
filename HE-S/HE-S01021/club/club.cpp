#include <bits/stdc++.h>
using namespace std;
const int N = 201000;
int t, n, ma, a1[N], a2[N], a3[N], b[2010];
void dfs(int x, int y, int z, int l){
	if(y > n / 2 || z > n / 2 || l > n / 2) return;
	if(x == n + 1){
		int ans = 0;
		for(int i = 1; i <= n; i++)
			if(b[i] == 0)
				ans += a1[i];
			else if(b[i] == 1)
				ans += a2[i];
			else
				ans += a3[i];
		ma = max(ans, ma);
		return;
	}
	b[x] = 0;
	dfs(x + 1, y + 1, z, l);
	b[x] = 1;
	dfs(x + 1, y, z + 1, l);
	b[x] = 2;
	dfs(x + 1, y, z, l + 1);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for(; t--; ){
		scanf("%d", &n);
		ma=  0;
		for(int i = 1; i <= n; i++){
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			a1[i] = x, a2[i] = y, a3[i] = z;
		}
		stable_sort(a3 + 1, a3 + n + 1);
		reverse(a3 + 1, a3 + n + 1);
		if(a3[1] == 0){
			stable_sort(a1 + 1, a1 + n + 1);
			stable_sort(a2 + 1, a2 + n + 1);
			reverse(a1 + 1, a1 + n + 1);
			reverse(a2 + 1, a2 + n + 1);
			int ans = 0;
			for(int i= 1; i <= n / 2; i++)
				ans += a1[i];
			for(int i = 1; i <= n / 2; i++)
				ans += a2[i];
			printf("%d\n", ans);
		} else{
			dfs(1, 0, 0, 0);
			printf("%d\n", ma);
		}
	}
	return 0;
}
