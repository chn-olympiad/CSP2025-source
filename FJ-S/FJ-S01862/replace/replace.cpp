#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::clog;

std::unordered_map<std::string, std::string> map;

int main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin.tie(nullptr); cout.tie(nullptr); std::ios::sync_with_stdio(false);
	
	int n, T;
	cin >> n >> T;
	
	while(n-- > 0) {
		
		std::string x, y;
		cin >> x >> y;
		
		map[x] = y;
	}
	
	while(T-- > 0) {
		
		std::string x, y;
		cin >> x >> y;
		
		int ans = 0;
		
		for(std::pair<std::string, std::string> val : map) {
			
			for(int i = 0; i < x.size(); ++i) {
				
				if(x.substr(i, val.first.size()) == val.first) {
					
					std::string tmp = x;
					x = x.substr(0, i) + val.second + x.substr(i + val.first.size());
					
					if(x == y) {
						
						++ans;
					}
					
					x = tmp;
				}
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
