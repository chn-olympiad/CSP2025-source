#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
	ll id, rval;
	pair < int, int > wt;
	bool operator < (const node & rhs) const {
		return rval < rhs.rval;
	} 
};
const int M = 1e5 + 10;
int n;
ll a[M][4], w[M][4], cnt[4], ans, bel[M], now[M];
priority_queue < node > q[4];
bool flag1 = 1;

void input() {
	cin >> n;
	for (int i = 1; i <= n; i ++) 
		cin >> a[i][1] >> a[i][2] >> a[i][3], flag1 &= (a[i][2] == 0 && a[i][3] == 0);
}

void dfs(int step) {
	if (step > n) {
		int sum = 0;
		vector < int > cnt(4);
		for (int i = 1; i <= n; i ++) 
			sum += a[i][now[i]], cnt[now[i]] ++;
		if (cnt[1] > n / 2 || cnt[2] > n / 2 || cnt[3] > n / 2) return ;
		if (sum >= ans) {
			ans = sum;
		}
		return ;
	}
	now[step] = 1;
	dfs(step + 1);
	now[step] = 2;
	dfs(step + 1);
	now[step] = 3;
	dfs(step + 1);
	now[step] = 0;
}

void work2() {
	for (int i = 1; i <= n; i ++) now[i] = 0;
	ans = 0; 
	dfs(1);
	cout << ans << "\n";	
}

bool add1(int p, int se) {
	auto t = q[1].top();
	while (!q[1].empty() && bel[t.id] != 1) {
		q[1].pop();
		t = q[1].top();
	}
	if (a[p][1] + t.rval <= a[p][se]) return 0;
	ans += a[p][1] + t.rval; bel[p] = 1;
	q[1].push(node{p, a[p][2] - a[p][1], make_pair(1, 2)});
	q[1].push(node{p, a[p][3] - a[p][1], make_pair(1, 3)});
	int pos = t.id, gt = t.wt.second;
	bel[pos] = gt;
	cnt[gt] ++;
	q[gt].push(node{pos, a[pos][1] - a[pos][gt], make_pair(gt, 1)});
	q[gt].push(node{pos, a[pos][5 - gt] - a[pos][gt], make_pair(gt, 5 - gt)});
	return 1;
}

bool add2(int p, int se) {
	auto t = q[2].top();
	while (!q[2].empty() && bel[t.id] != 2) {
		q[2].pop();
		t = q[2].top();
	}
	if (a[p][2] + t.rval <= a[p][se]) return 0;
	ans += a[p][2] + t.rval; bel[p] = 2;
	q[2].push(node{p, a[p][1] - a[p][2], make_pair(2, 1)});
	q[2].push(node{p, a[p][3] - a[p][2], make_pair(2, 3)});
	int pos = t.id, gt = t.wt.second;
	bel[pos] = gt;
	cnt[gt] ++;
	q[gt].push(node{pos, a[pos][2] - a[pos][gt], make_pair(gt, 2)});
	q[gt].push(node{pos, a[pos][4 - gt] - a[pos][gt], make_pair(gt, 4 - gt)});
	return 1;
}

bool add3(int p, int se) {
	auto t = q[3].top();
	while (!q[3].empty() && bel[t.id] != 3) {
		q[3].pop();
		t = q[3].top();
	}
	if (a[p][3] + t.rval <= a[p][se]) return 0;
	int pos = t.id, gt = t.wt.second;
	ans += a[p][3] + t.rval;
	bel[p] = 3;
	cnt[gt] ++;
	q[3].push(node{p, a[p][1] - a[p][3], make_pair(3, 1)});
	q[3].push(node{p, a[p][2] - a[p][3], make_pair(3, 2)});
	bel[pos] = gt;
	q[gt].push(node{pos, a[pos][3] - a[pos][gt], make_pair(gt, 3)});
	q[gt].push(node{pos, a[pos][3 - gt] - a[pos][gt], make_pair(gt, 3 - gt)});
	return 1;
} 

void work() {
	for (int i = 1; i <= 3; i ++) {
		while (!q[i].empty()) q[i].pop();
	}
	ans = 0;
	cnt[1] = cnt[2] = cnt[3] = 0;
	for (int i = 1; i <= n; i ++) bel[i] = 0;
	for (int i = 1; i <= n; i ++) {
		if (a[i][1] >= a[i][2] && a[i][2] >= a[i][3]) {
			if (cnt[1] == n / 2) {
				if (add1(i, 2)) continue ;
				cnt[2] ++;
				bel[i] = 2;
				q[2].push(node{i, a[i][1] - a[i][2], make_pair(2, 1)});
				q[2].push(node{i, a[i][3] - a[i][2], make_pair(2, 3)});
				ans += a[i][2];
				continue ;
			} 
			ans += a[i][1];
			cnt[1] ++; bel[i] = 1;
			q[1].push(node{i, a[i][2] - a[i][1], make_pair(1, 2)});
			q[1].push(node{i, a[i][3] - a[i][1], make_pair(1, 3)});
		} else if (a[i][1] >= a[i][3] && a[i][3] >= a[i][2]) {
			if (cnt[1] == n / 2) {
				if (add1(i, 3)) continue ;
				cnt[3] ++; bel[i] = 3;
				q[3].push(node{i, a[i][1] - a[i][3], make_pair(3, 1)});
				q[3].push(node{i, a[i][2] - a[i][3], make_pair(3, 2)});
				ans += a[i][3];
				continue ;
			} 
			ans += a[i][1]; bel[i] = 1;
			cnt[1] ++;
			q[1].push(node{i, a[i][2] - a[i][1], make_pair(1, 2)});
			q[1].push(node{i, a[i][3] - a[i][1], make_pair(1, 3)});
		} else if (a[i][2] >= a[i][1] && a[i][1] >= a[i][3]) {
			if (cnt[2] == n / 2) {
				if (add2(i, 1)) continue ;
				cnt[1] ++; bel[i] = 1;
				q[1].push(node{i, a[i][2] - a[i][1], make_pair(1, 2)});
				q[1].push(node{i, a[i][3] - a[i][1], make_pair(1, 3)});
				ans += a[i][1];
				continue ;
			} 
			ans += a[i][2]; bel[i] = 2;
			cnt[2] ++;
			q[2].push(node{i, a[i][1] - a[i][2], make_pair(2, 1)});
			q[2].push(node{i, a[i][3] - a[i][2], make_pair(2, 3)});
		} else if (a[i][2] >= a[i][3] && a[i][3] >= a[i][1]) {
			if (cnt[2] == n / 2) {
				if (add2(i, 3)) continue ;
				cnt[3] ++; bel[i] = 3;
				q[3].push(node{i, a[i][1] - a[i][3], make_pair(3, 1)});
				q[3].push(node{i, a[i][2] - a[i][3], make_pair(3, 2)});
				ans += a[i][3];
				continue ;
			} 
			bel[i] = 2;
			ans += a[i][2];
			cnt[2] ++;
			q[2].push(node{i, a[i][1] - a[i][2], make_pair(2, 1)});
			q[2].push(node{i, a[i][3] - a[i][2], make_pair(2, 3)});
		} else if (a[i][3] >= a[i][1] && a[i][1] >= a[i][2]) {
			if (cnt[3] == n / 2) {
				if (add3(i, 1)) continue ;
				cnt[1] ++; bel[i] = 1;
				q[1].push(node{i, a[i][2] - a[i][1], make_pair(1, 2)});
				q[1].push(node{i, a[i][3] - a[i][1], make_pair(1, 3)});
				ans += a[i][1];
				continue ;
			} 
			ans += a[i][3]; bel[i] = 3;
			cnt[3] ++;
			q[3].push(node{i, a[i][1] - a[i][3], make_pair(3, 1)});
			q[3].push(node{i, a[i][2] - a[i][3], make_pair(3, 2)});
		} else {
			if (cnt[3] == n / 2) {
				if (add3(i, 2)) continue ;
				cnt[2] ++; bel[i] = 2;
				q[2].push(node{i, a[i][1] - a[i][2], make_pair(2, 1)});
				q[2].push(node{i, a[i][3] - a[i][2], make_pair(2, 3)});
				ans += a[i][2];
				continue ;
			} 
			ans += a[i][3]; bel[i] = 3;
			cnt[3] ++;
			q[3].push(node{i, a[i][1] - a[i][3], make_pair(3, 1)});
			q[3].push(node{i, a[i][2] - a[i][3], make_pair(3, 2)});
		}
	}
	cout << ans << "\n"; 
}

void work3() {
	vector < int > vec;
	for (int i = 1; i <= n; i ++) vec.push_back(a[i][1]);
	sort(vec.begin(), vec.end(), greater < int > ());
	ans = 0;
	for (int i = 0; i < n / 2; i ++) ans += vec[i];
	cout << ans << "\n";
}

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t; cin >> t;
	while (t --) {
		input();
		if (n <= 10) work2();
		else if (flag1) {
			work3();
		} else {
			work();
		}
	}
	
	return 0;
}
