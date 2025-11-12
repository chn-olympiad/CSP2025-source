#include<bits/stdc++.h>
using namespace std;

int n, a[5001], b[5001], top, sum;

void dfs(int i){
	if(i == n + 1){
		if(top < 3)
			return;
		int ans = 0, ma = 0;
		for(int j = 1; j <= top; j++)
			ans += b[j], ma = max(b[j], ma);
		if(ans > 2 * ma)
			sum = (sum + 1) % 998244353;
		return;
	}
	dfs(i + 1);
	b[++top] = a[i];
	dfs(i + 1);
	top--;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dfs(1);
	printf("%d\n", sum);
	return 0;
}
