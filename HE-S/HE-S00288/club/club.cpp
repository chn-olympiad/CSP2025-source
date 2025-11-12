#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 1e5 + 10;

ll t, n, a[N][5], k[N][5], sum[5], ans;
pair<int, int> b[5];
struct Node{
	int id, kth, c;
	bool operator<(const struct Node &T) const{
		return c > T.c;
	}
};
priority_queue<Node> q[5];

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			b[1].fi = a[i][1], b[1].se = 1;
			b[2].fi = a[i][2], b[2].se = 2;
			b[3].fi = a[i][3], b[3].se = 3;
			sort(b + 1, b + 4);
			k[i][1] = b[3].se, k[i][2] = b[2].se, k[i][3] = b[1].se;
		}
		
		for(int i = 1;i <= n;i++){
			int fir = k[i][1];
			if(sum[fir] == n / 2){
				int u = q[fir].top().id, kth = q[fir].top().kth, cha = q[fir].top().c;
				int o = a[i][fir] - a[i][k[i][2]];
				if(cha < o){
					q[fir].pop();
					ans -= a[u][k[u][kth]];
					int id = k[u][kth + 1];
					sum[id]++;
					ans += a[u][id];
					q[id].push({u, kth + 1, a[u][k[u][kth + 1]] - a[u][k[u][kth + 2]]});
					q[fir].push({i, 1, a[i][fir] - a[i][k[i][2]]});
					ans += a[i][fir]; 
				} else {
					int sec = k[i][2];
					sum[sec]++;
					q[sec].push({i, 2, a[i][sec] - a[i][k[i][3]]});
					ans += a[i][sec];
				}
			} else {
				ans += a[i][fir]; 
				q[fir].push({i, 1, a[i][fir] - a[i][k[i][2]]});
				sum[fir]++;
			}
			//cout << ans << '\n';
		}
		cout << ans << '\n';
		
		sum[1] = sum[2] = sum[3] = 0;
		ans = 0;
		for(int i = 1;i <= 3;i++){
			while(!q[i].empty()) q[i].pop();
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

Ren5Jie4Di4Ling5%
*/

