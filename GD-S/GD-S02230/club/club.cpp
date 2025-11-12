#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int N = 1e5 + 10;
const int inf = 2e9;

struct node {
	pii pi[4];
} qq[N];

int n, n2, a, b, c, ans;
priority_queue<pii, vector<pii>, less<pii>> pq[4];

bool fight(int who, int to) {
	if (qq[who].pi[2].first - qq[who].pi[3].first < pq[to].top().first) {
		ans += pq[to].top().first;
//		printf("Fight! %d -> %d\n", pq[to].top().first, ans);
		pq[to].pop();
		return true;
	}
	return false;
}

void Add(int k) {
	sort(qq[k].pi+1, qq[k].pi+4);
	if (pq[qq[k].pi[3].second].size() < n2 || fight(k, qq[k].pi[3].second)) {
		pq[qq[k].pi[3].second].push(make_pair(qq[k].pi[2].first - qq[k].pi[3].first, qq[k].pi[2].second));
		ans += qq[k].pi[3].first;
//		printf("OK : %d %d -> %d   sz:%d %d %d\n", k, qq[k].pi[3].first, ans, pq[1].size(), pq[2].size(), pq[3].size());
	} else {
		pq[qq[k].pi[2].second].push(make_pair(qq[k].pi[3].first - qq[k].pi[2].first, qq[k].pi[3].second));
		ans += qq[k].pi[2].first;
//		printf("FAIL : %d %d -> %d   sz:%d %d %d\n", k, qq[k].pi[2].first, ans, pq[1].size(), pq[2].size(), pq[3].size());
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	scanf("%d", &t);
	while (t--) {
		while (!pq[1].empty()) pq[1].pop();
		while (!pq[2].empty()) pq[2].pop();
		while (!pq[3].empty()) pq[3].pop();
		ans = 0;
		
		scanf("%d", &n);
		n2 = n >> 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				scanf("%d", &qq[i].pi[j].first);
				qq[i].pi[j].second = j;
			}
			Add(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}

