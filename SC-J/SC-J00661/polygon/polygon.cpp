#include <bits/stdc++.h>
using namespace std;

int n, m[5005], ans = 0;

void dfs(int dep, int x, int sum){
	if(dep >= 3){
		if(sum > m[x]){
			ans++;
		}
		if(dep == n)
			return;
	}
	sum += m[x];
	for(int i = x + 1; i <= n; i++){
		dfs(dep + 1, i, sum);
	}
	
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> m[i];
	}
	sort(m + 1, m + n + 1);
	for(int i = 1; i <= n - 2; i++){
		dfs(1, i, 0);
	} 
	ans = ans % 998244353;
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}