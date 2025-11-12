#include <iostream>
#include <ios> 

using namespace std;

int n;
int a[5005];
//int vis[5005];

int dfs(int step, int sum, int max_val, int selected) {
	int ans = 0;
	
	if (step == n + 1) {
		
		if (sum > max_val * 2 && selected >= 3) {
			
			return 1;
		}
		
		return 0;
	}
	
	ans = dfs(step + 1, sum + a[step], max(max_val, a[step]), selected + 1)	// ัก 
	    + dfs(step + 1, sum, max_val, selected); // ฒปัก 
	
	return ans;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	
	ios::sync_with_stdio(false);
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	cout << dfs(1, 0, 0, 0);

	return 0;
}

