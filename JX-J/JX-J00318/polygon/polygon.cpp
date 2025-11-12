#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n;
int a[N], ans[N], sumans = 0;
void dfs(int k) {
	if(k == n+1) {
		int cnt = 0, ma = 0;
		long long sum = 0;
		for(int i = 1; i <= n; i++) {
			
			if(ans[i]) {
				cnt++;
				ma = max(ma, a[i]);
				sum += a[i];
			}
		}
		if(cnt >= 3 && sum > ma * 2) {
			sumans++;
		}
		return ;
	}
	ans[k] = 1;
	dfs(k+1);
	ans[k] = 0;
	dfs(k+1);
	return ;
}		
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1);
	cout << sumans;
    return 0;
}
