#include<bits/stdc++.h>
using namespace std;
long long id, n, k, a[100005], maxn;
bool vis[100005];
void dfs(long long sum, long long num, long long id){
	if (sum == k){
		sum = -1;
		num++;
	}
	if (id > n){
		maxn = max(maxn, num);
		return;
	}
	if (!vis[id]){
		if (sum == -1) sum = 0;
		vis[id] = 1;
		dfs(sum ^ a[id], num, id + 1);
		vis[id] = 0;
	}
	dfs(-1, num, id + 1);
	return;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld", &n);
	scanf("%lld", &k);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		if (a[i] == k){
			vis[i] = 1;
			maxn++;
		}
	}
	dfs(-1, maxn, 1);
	printf("%d", maxn);
	return 0;
}
