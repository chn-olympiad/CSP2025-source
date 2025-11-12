#include<bits/stdc++.h>
using namespace std;
int nums[5005];
int main() {
	freopen("polygon.in", "r", stdin);//#Shang4Shan3Ruo6Shui4
	freopen("polygon.out", "w", stdout);
	
	int n;
	cin >> n;
	
	int sum = 0;
	int maxn = 0;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		sum += nums[i];
		maxn = max(nums[i], maxn);
	}
	int cnt = 0;
	if (sum > 2*maxn) {
		cnt++;
	}
	
	
	cout << cnt;		
	return 0;
}
