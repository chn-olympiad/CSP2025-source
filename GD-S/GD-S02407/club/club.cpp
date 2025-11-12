#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500010;
int a[N][10], b[N][10];
bool c[N][10];
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while(T --) {
		memset(c, 0, sizeof(c));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int n, ans = 0; cin >> n;
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= 3;j ++) cin >> a[i][j];
		} 
		for(int i = 1;i <= n;i ++) {
			int maxn = INT_MIN;
			for(int j = 1;j <= 3;j ++) {
				maxn = max(maxn, a[i][j]);
			} ans += maxn;
			for(int j = 1;j <= 3;j ++) {
				b[i][j] = maxn - a[i][j];
				if(a[i][j] == maxn) c[i][j] = true;
			}
		} 	
		int fov = 0, shu = 0;
		for(int i = 1;i <= 3;i ++) {
			shu = 0;
			for(int j = 1;j <= n;j ++) {
				if(c[j][i]) shu ++;
			} 
			if(shu > n / 2) {
				fov = i;
				break;
			}
		} if(fov == 0) {
			cout << ans << endl;
		} else {
			vector<int> vec;
			for(int i = 1;i <= n;i ++) {
				if(c[i][fov]) {
					int mine = INT_MAX;
					for(int j = 1;j <= 3;j ++) {
						if(j == fov) continue;
						mine = min(mine, b[i][j]);
					} vec.push_back(mine);
				}
			} sort(vec.begin(), vec.end());
			for(int i = 0;i < shu - (n / 2);i ++) {
				ans -= vec[i];
			} cout << ans << endl;
		}
	}
	return 0;
} 
