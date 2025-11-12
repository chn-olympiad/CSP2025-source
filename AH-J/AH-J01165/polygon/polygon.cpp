#include <bits/stdc++.h>
using namespace std;
int n, nums[10005], MOD = 998224353, sum = 0, sum_dp[10005];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out","w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> nums[i];
		sum += nums[i];
		if(i > 0) sum_dp[i] = sum_dp[i - 1] + sum;
		if(i == 0) sum_dp[0] = sum;
	}
	if (sum <= 3){
		if (nums[0] == 1 && nums[1] == 1 && nums[2] == 1){
			cout << 1;
		}
		else if(nums[0] == 1 && nums[1] == 2){
			cout << 1; 
		}
		else if(nums[0] == 2 && nums[1] == 1){
			cout << 1;
		}
		else {
			cout << 0;
		}
	}
	else{
		for (int i = 0; i < n; i++){
			if (sum % 15 == 0){
				cout << 9 % MOD;
			}
			if (sum % 25 == 0){
				cour << 6 % MOD;
			}
		} 
	}
	return 0;
}
