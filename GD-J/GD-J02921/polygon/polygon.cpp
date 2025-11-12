#include <bits/stdc++.h>

using namespace std;

constexpr int N = 5e3 + 7;
int Mod = 998244353;
int a[N];
int n;
int cnt;

void dfs(int sum, int num, int id, int maxn) { 
    
    if(sum > 2 * maxn) {
    	int p = 1;
    	for(int i = id; i <= n; i++) {
    		p = (p * 2) % Mod;
		}
		cnt = (cnt + p) % Mod;
		return;
	}
	if(id == n + 1) return;
	
	dfs(sum + a[id], num + 1, id + 1, max(maxn, a[id]));
	dfs(sum, num, id + 1, maxn);
	
}

int main() {
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == 1) sum += 1;
	}
	
	if(sum == n) {
		int p = 1;
		for(int i = 1; i <= n - 4; i++) {
			p = 1;
			for(int j = 1; j <= i; j++) {
				p = p * 2 % Mod;
			}
			cnt = (cnt + p) % Mod;
		}
		cout << (cnt + 1) % Mod;
		return 0;
	}
	
	sort(a + 1, a + n + 1, greater<int>() );
	
	dfs(0, 0, 1, 0);
	
	cout << cnt;

	return 0;
}
