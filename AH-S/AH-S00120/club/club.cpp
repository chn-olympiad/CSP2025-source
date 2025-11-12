#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
struct node {
	int a[3], maxid;
} Q[N + 10];

int n;
vector <int> b[3];
void clear() {
	for(int i = 0; i < 3; i++)
		b[i].clear();
}
void init() {
	cin >> n;
	int sum = 0, c[3] = {0, 0, 0};
	for(int i = 1; i <= n; i++) {
		Q[i].maxid = 0;
		for(int j = 0; j < 3; j++)
			cin >> Q[i].a[j];
		for(int j = 1; j < 3; j++)
			if(Q[i].a[j] > Q[i].a[Q[i].maxid])
				Q[i].maxid = j;
		sum += Q[i].a[Q[i].maxid];
		c[Q[i].maxid]++;

		int tmp = Q[i].a[Q[i].maxid];
		for(int j = 0; j < 3; j++)
			if(j != Q[i].maxid)
				tmp = min(tmp, Q[i].a[Q[i].maxid] - Q[i].a[j]);
		b[Q[i].maxid].push_back(tmp);
	}

	int maxid = 0;
	for(int i = 0; i < 3; i++) {
		sort(b[i].begin(), b[i].end());
		if(c[i] > c[maxid]) maxid = i;
	}
	if(c[maxid] > n / 2) {
		for(int i = 0; i < c[maxid] - n / 2; i++)
			sum -= b[maxid][i];
	}
	cout << sum << endl;
	clear();
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while(T--) init();
}