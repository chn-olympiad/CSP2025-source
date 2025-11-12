#include<bits/stdc++.h>
using namespace std;
int n, m;
int bs = 200000;
struct node{
	int l, r;
};
vector<node> cnt[400005];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++) {
		int a, b, c = 1;
		string t1, t2;
		cin >> t1 >> t2;
		for (int j = 0 ; j < t1.size() ; j++) {
			if (t1[j] == 'b') a = j;
		}
		for (int j = 0 ; j < t2.size() ; j++) {
			if (t2[j] == 'b') b = j;
		}
		cnt[bs + a - b].push_back({a, t1.size() - a - 1});
	}
	while (m--) {
		int a, b, c = 1;
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << 0 << endl;
			continue;
		}
		for (int j = 0 ; j < t1.size() ; j++) {
			if (t1[j] == 'b') a = j;
		}
		for (int j = 0 ; j < t2.size() ; j++) {
			if (t2[j] == 'b') b = j;
		}
		int ans = 0;
		for (node j : cnt[bs + a - b]) {
			if (a >= j.l && t1.size() - a - 1 >= j.r) ans++;
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

