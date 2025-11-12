#include <bits/stdc++.h>

using namespace std;

struct opinion {
	int subject;
	int club;
	int score;
	bool operator < (const opinion & o) const {
		return score < o.score;
	}
	bool operator > (const opinion & o) const {
		return score > o.score;
	}
};
int n;
const int maxn = 1e5 + 1;
int member[4];
vector<priority_queue<opinion> > most(maxn);
vector<priority_queue<opinion, vector<opinion>, greater<opinion> > > least(4);
void process() {
	int input;
	cin >> n;
	most.assign(n + 1, priority_queue<opinion>());
	least.assign(4, priority_queue<opinion, vector<opinion>, greater<opinion> >());
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> input;
			most[i].push({i, j, input});
		}
	}
	for (int i = 1; i <= n; i++) {
		int sc = most[i].top().score;
		int location = most[i].top().club;
		least[location].push({i, location, sc});
	}
	for (int j = 1; j <= 3; j++) {
		while (least[j].size() > n / 2) {
			int least_sub = least[j].top().subject;
			least[j].pop();
			most[least_sub].pop();
			int semi_pos = most[least_sub].top().club;
			int semi_sc = most[least_sub].top().score;
			least[semi_pos].push({least_sub, semi_pos, semi_sc}); 
		}
	}
	int ans = 0;
	for (int j = 1; j <= 3; j++) {
		while (!least[j].empty()) {
			ans += least[j].top().score;
			least[j].pop();
		}
	}
	cout << ans << endl;
	most.clear();
	least.clear();
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		process();
	}
}
