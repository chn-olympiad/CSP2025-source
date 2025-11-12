#include<bits/stdc++.h>
#define int long long

signed main() {
	std::freopen("xor.in", "r", stdin);
	std::freopen("xor.out", "w", stdout);
	
	bool sp_a = true;
	bool sp_b = true;
	int n, k; std::cin >> n >> k;
	std::vector<int> s(n + 1);
	for(int i = 1; i <= n; i++) {
		std::cin >> s[i];
		if(s[i] != 1) {
			sp_a = false;
			if(s[i] != 0) {
				sp_b = false;
			}
		} 
	} 
	
	if(sp_a) {
		if(k == 1) {
			std::cout << n;
		} else if(k == 0) {
			std::cout << n / 2;
		} else {
			std::cout << 0;
		}
		
		
		std::fclose(stdin);
		std::fclose(stdout);
		
		return 0;
	}
	if(sp_b) {
		if(k == 1) {
			std::cout << std::count(s.begin() + 1, s.end(), 1); 
		} else if(k == 0) {
			std::cout << std::count(s.begin() + 1, s.end(), 1) / 2; 
		} else {
			std::cout << 0;
		}
		
		std::fclose(stdin);
		std::fclose(stdout);
		
		return 0;
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = i; j <= n; j ++) {
			int xor_sum = s[i];
			for(int x = i + 1; x <= j; x++) {
				xor_sum ^= s[i];
			}
			if(xor_sum == k) {
				cnt++;
			}
		}
	}
	
	std::cout << cnt;
	
	std::fclose(stdin);
	std::fclose(stdout);
	
	return 0;
}
