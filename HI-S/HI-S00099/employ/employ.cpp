#include <bits/stdc++.h>
using namespace std;

long long n, m;
string s;
int a[1005];

int cnt = 0;

void dfs(int x, vector<int> v, vector<int> k) {
	k.push_back(x);
	
	if (k.size() == n) {
		int t = 0; // 放弃或不通过人数 
		for (int i = 0; i < k.size(); i ++) {
			if (t >= k[i]) {
				t ++;
			}
			if (s[i] == '0') {
				t ++;
			}
		}
		if (n - t >= m) {
			cnt ++;
		} 
	}
	
	for (int i = 0; i < v.size(); i ++) {
		if (x == v[i]) {
			return;
		}
	}
	for (int i = 1; i <= n; i ++) {
		vector<int> vv = v;
		vv.push_back(i);
		dfs(i, vv, k);
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i ++) {
		dfs(i, {}, {});
	}

	cout << cnt << endl;
	return 0;
}
