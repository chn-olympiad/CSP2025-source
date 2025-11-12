#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::clog;

constexpr size_t N = 1e5 + 5;

struct peo {
	
	int value, id;
};

peo p[N][3];

int main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin.tie(nullptr); cout.tie(nullptr); std::ios::sync_with_stdio(false);
	
	int T;
	cin >> T;
		
	while(T-- > 0) {
		
		int n;
		cin >> n;
		
		for(int i = 1; i <= n; ++i) {
			
			for(int j = 0; j < 3; ++j) {
				
				cin >> p[i][j].value;
				p[i][j].id = j;
			}
			
			std::sort(p[i], p[i] + 3, [](peo x, peo y) {
				
				return x.value > y.value;
			});
		}
	
		std::priority_queue<int> max[3];
		int ans = 0;
		
		for(int i = 1; i <= n; ++i) {
			
			ans += p[i][0].value;
			max[p[i][0].id].emplace(p[i][1].value - p[i][0].value);
			
			if(max[p[i][0].id].size() > (n >> 1)) {
				
				ans += max[p[i][0].id].top();
				max[p[i][0].id].pop();	
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
