#include <iostream>
#include <vector> 
using namespace std;

int n;
int ans = INT_MIN;
int club[4] = {0};

void dfs(vector<vector<int> > A, int nowline, int now) {
	if(nowline > n) {
		ans = max(ans, now);
		return;
	}
	for(int i = 1; i <= 3; i++) {
		if(club[i] <= n / 2) {
			club[i]++;
			dfs(A, nowline + 1, now + A[nowline][i]);
			club[i]--;
		}
	}
}

int main() {
	freopen("club.out", "w", stdout);
	freopen("club.in", "r", stdin);
	
	int t;
	cin >> t;
	
	while(t--) {
		cin >> n;
		
		vector<vector<int> > A(n + 1, vector<int>(4));
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				cin >> A[i][j];
			}
		}
		
		dfs(A, 1, 0);
		
		cout << ans;
	}
	return 0;
}
