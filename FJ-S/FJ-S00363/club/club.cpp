#include<bits/stdc++.h>
using namespace std;
int a[100005][5];
int b[100005];
int ans = -1;
int n;
void dfs(int s){
	if (s > n){
		int sum = 0;
		int z[5] = {};
		for (int i = 1; i <= n; i++){
			z[b[i]]++;
			sum += a[i][b[i]]; 
		}
		if (z[1] <= n / 2 && z[2] <= n / 2 && z[3] <= n / 2){
			ans = max(ans, sum);
		}
		return;
	}
	b[s] = 1;
	dfs(s + 1);
	b[s] = 2;
	dfs(s + 1);
	b[s] = 3;
	dfs(s + 1);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		ans = 0;
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
