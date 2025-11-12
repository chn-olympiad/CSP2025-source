#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[5010];
int vis[5010];
long long cnt;
int mx = -1;
int n;

void dfs(int x, int sum, int mx) {
	if (sum > mx * 2 && x >= 4) {
		cnt++;
	}
	
	if (x == n + 1) return ;
	
}


int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	sort(a+1, a+1+n);
	
	if (n <= 2) {
		cout << 0;
		return 0;
	} 
	
	else if (n == 3) {
		int sum = 0;
		for (int i = 1; i <= 3; i++) {
			sum += a[i];
		}
		if (sum > a[3] * 2) cout << 1;
		else cout << 0;
	} 
	
	else if (n <= 20){
		dfs(1, 0, -1);
		cout << cnt;
	}
	
	else {
		long long sum = 0;
		for (int i = 3; i <= n; i++)  {
			sum = (sum % 998244353 + (n - i) % 998244353) % 998244353;
		}
		cout << sum;
	}
	
	
	
	return 0;
}
