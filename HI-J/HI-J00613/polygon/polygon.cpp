#include<bits/stdc++.h>
using namespace std;
int a[5005], n, ans = 0; 
int b[5005];
bool check() {
	int maxx = -2e9;
	int sum = 0;
	for(int i = 1; i < 5000; i++) {
		sum += i * b[i];
		if(b[i] != 0) {
			maxx = i;
		}
		
	}
	if(sum > maxx * 2) {
		return 1;
	} 
	
	return 0;
	
}
void dfs(int x) {
	if(x >= n){
		
		if(check()){
			ans++;
		}
		return ;
	}
	for(int i = x; i < n; i++) {
		
		b[a[i]]++;
		dfs(i + 1);
		b[a[i]]--;
		if(check()){
			ans++;
		}
		
	}
	
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dfs(0);
	for(int i = 0; i < n; i++) {
		b[a[i]]++;
	}
	for(int i = 1; i < 5000; i++) {
		if(b[i] > 1) {
			ans -= b[i] - 1;
		}
	}
	cout << ans;
	return 0;
}
