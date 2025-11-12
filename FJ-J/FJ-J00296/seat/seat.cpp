#include<bits/stdc++.h>
using namespace std;
int nums[10500];
int main() {
	freopen("seat.in", "r", stdin);//#Shang4Shan3Ruo6Shui4
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	int a1 = 0;
	for (int i = 0; i < n * m; i++) {
		cin >> nums[i];
		if (i == 0) {
			a1 = nums[i];
		}
	}
	
	sort(nums, nums + n*m, greater<int>());
	
	int h,l;
	
	for (int i = 0; i < n * m; i++) {
		if (nums[i] == a1 && (i/n)%2 == 0) {
			h = i % n + 1;
			l = (i / n) + 1;
		} else if(nums[i] == a1) {			
			h = n - (i % n);
			l = (i / n) + 1;
		}
	}
	
	cout << l <<' ' << h;
	
	
	return 0;
}
