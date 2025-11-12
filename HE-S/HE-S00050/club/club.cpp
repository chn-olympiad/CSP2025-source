#include<bits/stdc++.h>

using namespace std;

const int SIZN = 1e5 + 10;

struct node {
	int val,id1,id2;
	node(int _v,int _i1,int _i2) {
		val = _v;
		id1 = _i1;
		id2 = _i2;
	}
	bool operator<(const node& nxt)const {
		return nxt.val < val;
	}
};
struct amon {
	pair<int,int> s[5];
};

int t;
int n;
int ans;
priority_queue<node> q[5];
amon per[SIZN];
void solve() {
	for(int i = 1 ; i <= n ; i++) {
		for(int j = 1 ; j <= 3 ; j++) {
			if(q[per[i].s[j].second].size() < n / 2) {
				q[per[i].s[j].second].push(node(per[i].s[j].first,i,j));
				ans += per[i].s[j].first;
				break;
			} else {
				int id1 = q[per[i].s[j].second].top().id1;
				int id2 = q[per[i].s[j].second].top().id2;
				if(q[per[i].s[j].second].top().val < per[i].s[j].first || per[i].s[j].first + per[id1].s[id2 + 1].first > per[i].s[j + 1].first + per[id1].s[id2].first) {
					q[per[i].s[j].second].pop();
					ans -= per[id1].s[id2].first;

					q[per[i].s[j].second].push(node(per[i].s[j].first,i,j));
					q[per[id1].s[id2 + 1].second].push(node(per[id1].s[id2 + 1].first,id1,id2 + 1));
					ans += per[i].s[j].first;
					ans += per[id1].s[id2 + 1].first;
				}

			}
		}
	}
	cout << ans << '\n';
}
void init() {
	memset(per,0,sizeof(per));
	while(!q[1].empty())q[1].pop();
	while(!q[2].empty())q[2].pop();
	while(!q[3].empty())q[3].pop();
	ans = 0;

	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		cin >> per[i].s[1].first;
		per[i].s[1].second = 1;
		cin >> per[i].s[2].first;
		per[i].s[2].second = 2;
		cin >> per[i].s[3].first;
		per[i].s[3].second = 3;

		for(int j = 1 ; j <= 3 ; j++) {
			for(int k = 1 ; k <= 2 ; k++) {
				if(per[i].s[k].first < per[i].s[k + 1].first) {
					swap(per[i].s[k],per[i].s[k + 1]);
				}
			}
		}
	}
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while(t--) {
		init();
		solve();
	}
	return 0;
}
