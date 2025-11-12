#include <bits/stdc++.h>
using namespace std;

int n;
 
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &n);
		vector<int> vec[3];
		int ans = 0;
		
		for (int i = 1; i <= n; ++i) {
			int a[3];
			
			for (int j = 0; j < 3; ++j)
				scanf("%d", a + j);
			
			int res = *max_element(a, a + 3);
			ans += res;
			
			if (a[0] == res)
				vec[0].emplace_back(max(a[1], a[2]) - res);
			else if (a[1] == res)
				vec[1].emplace_back(max(a[0], a[2]) - res);
			else
				vec[2].emplace_back(max(a[0], a[1]) - res);
		}
		
		for (int i = 0; i < 3; ++i) {
			sort(vec[i].begin(), vec[i].end());
			
			for (int j = n / 2; j < vec[i].size(); ++j)
				ans += vec[i][j];
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
} 
