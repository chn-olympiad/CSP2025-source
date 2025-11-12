#include<bits/stdc++.h>
using namespace std;
int a[5005];
int b[5005];
int n;
int ans;
void dfs(int s, int cnt){
	if (s > n){
		if (cnt <= 2)return;
		int sum = 0;
		int maxx = INT_MIN;
		for (int i = 1; i <= n; i++){
			sum += b[i] * a[i];
			maxx = max(maxx, a[i] * b[i]);
		}
		if (sum > maxx * 2){
			ans++; 
		}
		return;
	}
	b[s] = 1;
	dfs(s + 1, cnt + 1);
	b[s] = 0;
	dfs(s + 1, cnt);
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	dfs(1, 0);
	cout << ans;
	return 0;
}
