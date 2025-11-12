#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 5e5 + 5;

int a[N], s[N];
int f[N];

struct Node {
	int sum, id;
	bool operator<(const Node &other) const {
		if (sum != other.sum) return sum < other.sum;
		return id > other.id;
	}
};

void print(set<Node> s) {
	for (auto i = s.begin(); i != s.end(); i ++) {
		Node x = *i;
		cout << x.sum << ' ' << x.id << endl;
	}
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) s[i] = s[i - 1] ^ a[i];
	set<Node> se;
	for (int i = 1; i <= n; i ++) {
		f[i] = f[i - 1];
		se.insert({s[i - 1], i - 1});
		auto v = se.lower_bound({s[i] ^ k, n + 1});
		if (v != se.end()) {
			Node x = *v;
//			printf("i = %d, s[i] = %d, find(%d) = {sum = %d, id = %d}\n", i, s[i], s[i] ^ k, x.sum, x.id);
			if (x.sum == (s[i] ^ k)) {
//				printf("i = %d, j = %d\n", i, x.id);
				f[i] = max(f[i], f[x.id] + 1);
			}
		}
//		printf("i = %d\n", i);
//		print(se);
//		cout << endl;
	}
	cout << f[n];
	return 0;
}
