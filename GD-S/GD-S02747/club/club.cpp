#include <bits/stdc++.h>
using namespace std;
struct Node {
	int x, y, z; // x 是满意度， y 是员工编号，z 是第几个部门 
};
using pii = pair<int, int>;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T--) {
		int n, ans = 0;
		cin >> n;
		vector<bool> choose(n, false);
		vector<int> cnt(4, 0);
		vector<pii> maxi(n, {0, 0});
		vector<vector<int>> b(4, vector<int> (n));
		int tot = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 1; j <= 3; ++j) {
				cin >> b[j][i];
				if(maxi[i].first < b[j][i]) {
					maxi[i].first = b[j][i];
					maxi[i].second = j;
				}
			}
		}
		for(int i = 0; i < n; ++i) {
			cnt[maxi[i].second]++;
			ans += maxi[i].first;
		}	
		int id = -1;
		for(int i = 1; i <= 3; ++i) if(cnt[i] > n / 2) id = i;
		if(id != -1) {
			vector<pii> ti(n, {10000, 0});
			for(int i = 0; i < n; ++i) {
				ti[i].second = i;
				for(int j = 1; j <= 3; ++j) {
					if(j != id) {
						ti[i].first = min(ti[i].first, maxi[i].first - b[j][i]);
					}
					
				}
			}
			sort(ti.begin(), ti.end());
			int time = cnt[id] - (n / 2);
			for(int i = 0; i < n && time > 0; ++i) {
				while(ti[i].first == 0 && i < n) i++;
				ans -= ti[i].first;
				time--;
			}
			
		}
		cout << ans << '\n';
	}
	return 0;
}
