#include <bits/stdc++.h>
#define ll long long
#define PLI pair<ll, int>
#define _1 first
#define _2 second
using namespace std;
const int z = 1e5 + 7;
int n;
ll ans;
vector<PLI> vt[z];
vector<int> pt[7];
priority_queue<ll> pq;
bool cmp(PLI a, PLI b) {
	return a > b;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
	int T, hn;
	cin >> T;
	while(T--) {
		ans = 0;
		for(int i = 1; i <= n; ++i) vt[i].clear();
		for(int i = 1; i <= 3; ++i) pt[i].clear();
		cin >> n; hn = n / 2;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1, a; j <= 3; ++j) {
				cin >> a;
				vt[i].push_back({a, j});
			}
			sort(vt[i].begin(), vt[i].end(), cmp);
			pt[vt[i][0]._2].push_back(i), ans += vt[i][0]._1;
		}
		for(int i = 1; i <= 3; ++i) 
		if(pt[i].size() > hn) {
			for(int j : pt[i]) pq.push(vt[j][1]._1 - vt[j][0]._1);
			for(int j = 1, lm = pt[i].size() - hn; j <= lm; ++j) ans += pq.top(), pq.pop();
			while(!pq.empty()) pq.pop();
			break;
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
tanxin
O(nlogn)
fen:100
*/
