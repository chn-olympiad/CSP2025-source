#include<bits/stdc++.h>
#define int long long
signed main() {
	std::freopen("seat.in", "r", stdin);
	std::freopen("seat.out", "w", stdout);
	
	int n, m; std::cin >> n >> m;
	std::set<int, std::greater<int>> a;
	bool readed = 0;
	int a_s = 0;
	for(int i = 0; i < n * m; i ++) {
		int temp;
		std::cin >> temp;
		if(!readed) {
			a_s = temp;
			readed = true;
		}
		a.insert(temp);
	}
	
	int a_order = std::distance(a.begin(), a.find(a_s)) + 1; // starting by 1

	int r = 0, c = 0; 
	for(int i = 1; i <= m; i++) {

		if(a_order > n) {
			a_order -= n;
		} else {
			r = i;
			if(i % 2 == 0) {
				c = n - a_order + 1;
			} else {
				c = a_order;
			}
			break;
		}
	} 
	
	std::cout << r << ' ' << c;
	
	std::fclose(stdin);
	std::fclose(stdout);
	
	return 0;
}
