#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int t, n;
ll ans;
struct node{
	int num, id;
	ll val;
	bool operator < (const node& tmp) const {
		return val < tmp.val;
	}
};
struct Data{
	int val, id;
	bool operator < (const Data& tmp) const {
		return val > tmp.val;
	}
}a[N][4];
priority_queue<node> q[4];
int b[4];
void clear() {
	ans = 0;
	b[1] = b[2] = b[3] = 0;
	for(int i = 1; i <= 3; i ++) {
		while(!q[i].empty()) q[i].pop();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t --) {
		cin >> n;
		clear();
		for(int i = 1; i <= n; i ++) {
			int x, y, z;
			cin >> x >> y >> z;
			a[i][1] = {x, 1}, a[i][2] = {y, 2}, a[i][3] = {z, 3};
			sort(a[i] + 1, a[i] + 3 + 1);	
			b[a[i][1].id] ++;
			ans += a[i][1].val;
			q[a[i][1].id].push({i, 1, a[i][2].val - a[i][1].val});
		}
		while(b[1] > n / 2 || b[2] > n / 2 || b[3] > n / 2) {
			for(int i = 1; i <= 3; i ++) {
				if(b[i] <= n / 2) continue;
				int t = q[i].top().num;
				int g = q[i].top().id;
				ans += q[i].top().val;
				q[i].pop();
				b[i] --;
				if(g + 1 != 3) {
					b[a[t][g + 1].id] ++;
					q[a[t][g + 1].id].push({t, g + 1, a[t][g + 2].val - a[t][g + 1].val});
				}else {
					b[a[t][g + 1].id] ++;
					q[a[t][g + 1].id].push({t, g + 1, -999999999});
				}
				break;
			}
		}
		cout << ans << '\n';
		
	}
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
