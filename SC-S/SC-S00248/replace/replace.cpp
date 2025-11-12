#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, q;
int ans;

struct node {
	string s1, s2;
};
node a[N];

void dfs(int l, string t1, string t2, int id, int tot_cnt) {
	if (tot_cnt > 1) return;
	
	if (id == l + 1) {
		if (t1 == t2 && tot_cnt <= 1) {
			ans ++;
		}
		return;
	}
	
	if (t1[id] == t2[id]) dfs(l, t1, t2, id + 1, tot_cnt);
	
	for (int j = 1; j <= n; j ++) {
		string tmp;
		int tmpl = a[j].s1.size();
		for (int i = id; i <= id + tmpl - 1; i ++) {
			tmp += t1[i];
		}
		if (tmp == a[j].s1) {
			string tmptmp = t1;
			for (int i = id; i <= id + tmpl - 1; i ++) {
				t1[i] = a[j].s2[i - id];
			}
			
			dfs(l, t1, t2, id + tmpl, tot_cnt + 1);
			
			t1 = tmptmp;
		}
	}
}

void solve(string t1, string t2) {
	int l1 = t1.size(), l2 = t2.size();
	if (l1 != l2) {
		cout << 0 << '\n';
		return;
	}
	
	t1 = '#' + t1, t2 = '#' + t2;
	
	ans = 0;
	dfs(l1, t1, t2, 1, 0);
	cout << ans << '\n';
}

int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i].s1 >> a[i].s2;
	}
	
	for (int i = 1; i <= q; i ++) {
		string t1, t2; cin >> t1 >> t2;
		solve(t1, t2);
	}


	return 0;
}