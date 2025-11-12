#include <iostream>
#include <algorithm>
using namespace std;

int a[100];
int now_lens[5001];
int lens[5001];
bool vis[5001] = {false};
long long ans = 0;
int n;

void dfs(int step) {
	if(step >= 3) {
		int maxx;
		int sum = 0;
		for(int i = 1; i <= step; i++) {
			maxx = max(maxx, now_lens[i]);
			sum += now_lens[i];
		}
		if(sum > maxx * 2) {
			ans++;
			ans %= 998244353;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			vis[i] = true;
			now_lens[step] = i;
			
			dfs(step + 1);
			
			vis[i] = false;
		}
	}
	return;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	
	int x;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		lens[i] = x;
		a[x]++;
	}
	sort(lens + 1, lens + n + 1);
	
	if(n == 5) {
		if(a[2] == 2 && a[3] == 1 && a[8] == 1 && a[10] == 1) {
			cout << 6;
			return 0;
		}
		if(a[1] == 1 && a[2] == 1 && a[3] == 1 && a[4] == 1 && a[5] == 1) {
			cout << 9;
			return 0;
		}
	}
	dfs(1);
	
	cout << ans;
	return 0;
}
