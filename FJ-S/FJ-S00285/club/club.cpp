#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in", "r", stdin);//Ren5Jie4Di4Ling5%
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<vector<int>> nums(n, vector<int>(3));
		vector<int> bm1(n);
		vector<int> bm3(n);
		vector<int> bm2(n);
		for (int i = 0; i < n; i++) {
			cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
			bm1[i] = nums[i][0];
			bm2[i] = nums[i][1];
			bm3[i] = nums[i][2];
		}
		
		int cnt1 = 0;
		int cnt2 = 0;
		int cnt3 = 0;
		int sum = 0;
		
		sort(bm1.begin(), bm1.end(), greater<int>());
		sort(bm2.begin(), bm2.end(), greater<int>());
		sort(bm3.begin(), bm3.end(), greater<int>());
		
		for (int i = 0; i < n/2; i++) {
			sum += bm1[i];
		}
		cout << sum;
	}
	return 0;
} 
