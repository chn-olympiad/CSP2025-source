#include<bits/stdc++.h>
#define int long long

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	std::freopen("number.in", "r", stdin);
	std::freopen("number.out", "w", stdout);
	
	std::vector<int> nums;
	nums.reserve(10100);
	char ch;
	int maxx = 0;
	while(true) {
		ch = std::cin.get();
		if(ch == '\n' || ch == EOF) break;
		if(ch >= '0' && ch <= '9') {
			nums.push_back((int)(ch - '0'));
			maxx = std::max(maxx, (int)(ch - '0'));
		} 
	}
	

	if(maxx == 0){
		std::cout << 0;
		return 0;
	}
	std::sort(nums.begin(), nums.end(), cmp);
	
	for(auto i : nums) std::cout << i;
	
	std::fclose(stdin);
	std::fclose(stdout);
	
	return 0; 
} 
