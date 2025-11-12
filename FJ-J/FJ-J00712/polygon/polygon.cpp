#include <bits/stdc++.h>
using namespace std;

const int mod =  998244353;
int n, a[5005], ans;
bool vis[5005];

void dfs(int step, int maxa, int cnt, int last){
	if(cnt > maxa * 2 && step > 3)ans++;
	if(step > n || last >= n)return;
	for(int i = last + 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = true;
			dfs(step + 1, max(maxa, a[i]), cnt + a[i], i);
			vis[i] = false;
		}
	}
	ans %= mod;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	dfs(1, -1, 0, 0);
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
