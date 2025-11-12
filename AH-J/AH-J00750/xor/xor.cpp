#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[500005];
int ans;
void dfs(int cnt, int ansx, int sum){
	if(cnt == n+1){
		ans = max(ans, ansx);
		return;
	}
	sum = (sum^a[cnt]);
	cout << sum << ' ';
	if(sum == k){
		ansx++;
		dfs(cnt+1, ansx, 0);
		return;
	}
	dfs(cnt+1, ansx, 0);
	dfs(cnt+1, ansx, sum);
}
int main(){
	freopen("xor5.in", "r", stdin);
	freopen("xor5.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dfs(1,0,0);
	cout << ans << endl;
	return 0;
}
