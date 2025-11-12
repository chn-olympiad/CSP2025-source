#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

bool vis[11][11] = {false};
int nums[111];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n * m; i++) {
		cin >> nums[i];
	}
	int R_total = nums[1];
	sort(nums + 1, nums + n * m + 1, cmp);
	
	int r_it;
	for(int i = 1; i <= n * m; i++) {
		if(nums[i] == R_total) {
			r_it = i;
		}
	}
	vis[1][1] = true;
	
	int i = 1, j = 1;
	int count = 1;
	while(true) {
		// way1 is not good, who can help me?!! no!!!
		
		// down 
		while(!vis[i + 1][j] && (i + 1 <= n)) {
			count++;
			i++;
			vis[i][j] = true;
			if(count >= r_it) { 
				cout << j << " " << i << endl;
				return 0;
			}
		}
		// up up 
		while(!vis[i - 1][j] && (i - 1 >= 1)) {
			count++;
			i--;
			vis[i][j] = true;
			if(count >= r_it) {
				cout << j << " " << i << endl;
				return 0;
			}
		}
		// right 
		if((!vis[i][j + 1]) && (j + 1 <= m)) {
			count++;
			j++;
			vis[i][j] = true;
			if(count >= r_it) { 
				cout << j << " " << i << endl;
				return 0;
			}
		}
	}
	
	return 0;
}
