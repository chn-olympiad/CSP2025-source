#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxN 100010
int T, n;

struct Node {
	int idx, a1, a2, a3;
} a[maxN];

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while (T--) {
		ll ans = 0;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		set <int> s;
		priority_queue <pair<int, int>, vector<pair<int, int>>, less <pair<int, int>>> q1;
		priority_queue <pair<int, int>, vector<pair<int, int>>, less <pair<int, int>>> q2;
		priority_queue <pair<int, int>, vector<pair<int, int>>, less <pair<int, int>>> q3;
		cin>>n;
		for (int i = 1; i <= n; i++) {
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].idx = i;
			q1.push({a[i].a1, i});
			q2.push({a[i].a2, i});
			q3.push({a[i].a3, i});
		}
		for (int i = 1; i <= n; i++) {
			while (s.count(q1.top().second)) q1.pop();
			while (s.count(q2.top().second)) q2.pop();
			while (s.count(q3.top().second)) q3.pop();
//			cout<<q1.top().first<<' '<<q1.top().second<<' '
//			<<q2.top().first<<' '<<q2.top().second<<' '<<q3.top().first<<' '<<q3.top().second<<'\n';
	
			if (cnt1 < n/2 && q1.top().first >= q2.top().first && q1.top().first >= q3.top().first) {
				auto tmp = q1.top();
				q1.pop();
				ans += tmp.first;
				s.insert(tmp.second);
				cnt1++;
			} else if (cnt2 < n/2 && q2.top().first >= q1.top().first && q2.top().first >= q3.top().first) {
				auto tmp = q2.top();
				q2.pop();
				ans += tmp.first;
				s.insert(tmp.second);
				cnt2++;
			} else if (cnt3 < n/2 && q3.top().first >= q1.top().first && q3.top().first >= q1.top().first) {
				auto tmp = q3.top();
				q3.pop();
				ans += tmp.first;
				s.insert(tmp.second);
				cnt3++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
