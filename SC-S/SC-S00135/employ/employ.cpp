#include<bits/stdc++.h>
using namespace std;
#define nmax 507
#define mod 998244353
#define int long long

int n, m;
string diff;
int cnt[nmax];
int c[nmax];

vector<int> steck;
int ans = 0;
bool vis[nmax];
void dfs(int i) {
	if ((int)steck.size() == n) {
		int use = 0, kill = 0;

		for (int i = 0; i < n; i++) {
			if (diff[i] == '0') {
				kill++;
			} else if (kill < steck[i]) {
				use++;
			}
		}

		if (use >= m) {
			ans++;
		}

		return ;
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			steck.push_back(c[i]);
			dfs(i + 1);
			vis[i] = 0;
			steck.pop_back();
		}
	}
}

int f(int x) {
	int res = 1;

	for (int i = 1; i <= x; i++) {
		res *= i;
		res %= mod;
	}

	return res;
}

bool isa() {
	for (int i = 0; i < (int)diff.size(); i++) {
		if (diff[i] != '1') {
			return 0;
		}
	}

	return 1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	cin >> diff;

	for (int i = 1; i < (int)diff.size(); i++) {
		cnt[i] = cnt[i - 1];

		if (diff[i] == '0') {
			cnt[i]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	if (n <= 10) {
		dfs(1);
		cout << ans;
		return 0;
	} else if (isa()) {
		cout << f(n);
	}

	cout << 0;
	return 0;
}

/*
3 2
101
2 1 1
*/