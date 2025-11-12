#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
priority_queue<int,vector<int>,greater<int>> q[3];
int T,n,ans,a[N][3],cnt[3];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--) {
		for(int i = 0;i < 3;i++) {
			while(!q[i].empty())  q[i].pop();
		}
		ans = cnt[0] = cnt[1] = cnt[2] = 0;
		cin >> n;
		for(int i = 1;i <= n;i++) {
			for(int j = 0;j < 3;j++)  cin >> a[i][j];
		}
		for(int i = 1;i <= n;i++) {
			int id1,id2,mx1,mx2;
			id1 = id2 = mx1 = mx2 = -1;
			for(int j = 0;j < 3;j++) {
				if(a[i][j] >= mx1) {
					id2 = id1,mx2 = mx1;
					id1 = j,mx1 = a[i][j];
				}
				else if(a[i][j] >= mx2) {
					id2 = j,mx2 = a[i][j];
				}
			}
			if(cnt[id1] < n / 2) {
				cnt[id1]++,ans += mx1;
				q[id1].push(a[i][id1] - a[i][id2]);
			}
			else {
				if(ans + mx2 >= ans + mx1 - q[id1].top()) {
					cnt[id2]++,ans += mx2;
				}
				else {
					ans += mx1 - q[id1].top();
					q[id1].pop();
					q[id1].push(a[i][id1] - a[i][id2]);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
