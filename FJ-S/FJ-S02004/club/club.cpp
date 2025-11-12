#include <bits/stdc++.h>
const int N = 1e5 + 10;
int t;
int n;
int a[N][3], ans;
struct com {
	int id, w;
	friend bool operator < (com a, com b) {
		return a.w < b.w;
	}
};
std::priority_queue<com> q[3];
int val(int x, int y) {
	if(y == 0) return -a[x][0] + std::max(a[x][1], a[x][2]);
	if(y == 1) return -a[x][1] + std::max(a[x][0], a[x][2]);
	if(y == 2) return -a[x][2] + std::max(a[x][0], a[x][1]); 
}
void solve() {
	std::cin >> n;
	
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	
	
	for(int i = 1; i <= n; i++) {
		int maxn = std::max(a[i][0], std::max(a[i][1], a[i][2]));
		if(a[i][0] == maxn) {
			if(q[0].size() < n / 2) q[0].push({i, val(i, 0)}), ans += a[i][0];
			else {
				if(a[i][1] >= a[i][2]) {
					int pos = q[0].top().id;
					int ret = a[i][1], ret2 = -a[pos][0] + std::max(a[pos][1], a[pos][2]) + a[i][0];
					if(ret >= ret2) q[1].push({i, val(i, 1)}), ans += ret;
					else {
						ans += ret2;
						q[0].pop();
						q[0].push({i, val(i, 0)});
						if(a[pos][1] >= a[pos][2]) q[1].push({pos, val(pos, 1)});
						else q[2].push({pos, val(pos, 2)});
					}
				}
				else {
					int pos = q[0].top().id;
					int ret = a[i][2], ret2 = -a[pos][0] + std::max(a[pos][1], a[pos][2]) + a[i][0];
					if(ret >= ret2) q[2].push({i, val(i, 2)}), ans += ret;
					else {
						ans += ret2;
						q[0].pop();
						q[0].push({i, val(i, 0)});
						if(a[pos][1] >= a[pos][2]) q[1].push({pos, val(pos, 1)});
						else q[2].push({pos, val(pos, 2)});
					}
				}
			}
		} 
		else if(a[i][1] == maxn) {
			if(q[1].size() < n / 2) q[1].push({i, val(i, 1)}), ans += a[i][1];
			else {
				if(a[i][0] >= a[i][2]) {
					int pos = q[1].top().id;
					int ret = a[i][0], ret2 = -a[pos][1] + std::max(a[pos][0], a[pos][2]) + a[i][1];
					if(ret >= ret2) q[0].push({i, val(i, 0)}), ans += ret;
					else {
						ans += ret2;
						q[1].pop();
						q[1].push({i, val(i, 1)});
						if(a[pos][0] >= a[pos][2]) q[0].push({pos, val(pos, 0)});
						else q[2].push({pos, val(pos, 2)});
					}
				}
				else {
					int pos = q[1].top().id;
					int ret = a[i][2], ret2 = -a[pos][1] + std::max(a[pos][0], a[pos][2]) + a[i][1];
					if(ret >= ret2) q[2].push({i, val(i, 2)}), ans += ret;
					else {
						ans += ret2;
						q[1].pop();
						q[1].push({i, val(i, 1)});
						if(a[pos][0] >= a[pos][2]) q[0].push({pos, val(pos, 0)});
						else q[2].push({pos, val(pos, 2)});
					}
				}
			}
		} 
		else if(a[i][2] == maxn) {
			if(q[2].size() < n / 2) q[2].push({i, val(i, 2)}), ans += a[i][2];
			else {
				if(a[i][0] >= a[i][1]) {
					int pos = q[2].top().id;
					int ret = a[i][0], ret2 = -a[pos][2] + std::max(a[pos][0], a[pos][1]) + a[i][2];
					if(ret >= ret2) q[0].push({i, val(i, 0)}), ans += ret;
					else {
						ans += ret2; 
						q[2].pop();
						q[2].push({i, val(i, 2)});
						if(a[pos][0] >= a[pos][1]) q[0].push({pos, val(pos, 0)});
						else q[1].push({pos, val(pos, 1)});
					}
				}
				else {
					int pos = q[2].top().id;
					int ret = a[i][1], ret2 = -a[pos][2] + std::max(a[pos][0], a[pos][1]) + a[i][2];
					if(ret >= ret2) q[1].push({i, val(i, 1)}), ans += ret;
					else {
						ans += ret2;
						q[2].pop();
						q[2].push({i, val(i, 2)});
						if(a[pos][0] >= a[pos][1]) q[0].push({pos, val(pos, 0)});
						else q[1].push({pos, val(pos, 1)});
					}
				}
			}
		} 
	}
	
	std::cout << ans << "\n";
	
	for(int i = 0; i < 3; i++) {
//		std::cout << q[i].size() << "\n"; 
		while(!q[i].empty()) {
			q[i].pop();
		}
//		std::cout <<"\n";
	}
	ans = 0;
	return;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::cin >> t;
	
	while(t--) {
		solve();
	}
	
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/ 
