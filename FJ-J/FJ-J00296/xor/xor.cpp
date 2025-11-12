#include<bits/stdc++.h>
using namespace std;
int nums[500005];
int main() {
	freopen("xor.in", "r", stdin);//#Shang4Shan3Ruo6Shui4
	freopen("xor.out", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		maxi = max(maxi, nums[i]);
	}
	
	cout << maxi;
	
	return 0;
}
