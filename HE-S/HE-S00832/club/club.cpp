#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[5][300010];
struct st{
	int val;
	friend bool operator < (st a,st b) {
		return b.val < a.val;
	}
};
priority_queue<st> q[5];
int ans = 0;
void solve(int id) {
	int cnt = q[id].size() - n / 2;
	while(cnt) {
		int u = q[id].top().val;
		q[id].pop();
		ans -= u;
		cnt --;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t --) {
		ans = 0;
		cin >> n;
		while(q[1].size()) q[1].pop();
		while(q[2].size()) q[2].pop();
		while(q[3].size()) q[3].pop();
		for(int i=1;i<=n;i++) {
			cin >> a[1][i] >> a[2][i] >> a[3][i];
		}
		for(int i=1;i<=n;i++) {
			int p = max({a[1][i],a[2][i],a[3][i]});
			ans += p;
			if(a[1][i] == p) {
				q[1].push({p - max(a[2][i],a[3][i])});
			}
			else if(a[2][i] == p) {
				q[2].push({p - max(a[1][i],a[3][i])});
			}
			else {
				q[3].push({p - max(a[2][i],a[1][i])});
			}
		}
		
		if((int)q[1].size() > n / 2) {
			solve(1);
		}
		else if((int)q[2].size() > n / 2) {
			solve(2);
		}
		else if((int)q[3].size() > n / 2){
			solve(3);
		}
		cout << ans << '\n';
	}
	return 0;
}
