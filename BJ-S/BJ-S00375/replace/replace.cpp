#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, L = 2.5e6 + 10;

int n, q;
vector<int> S[N], T[N];
vector<int> opt[L], qry[L];

int tNode = 0;
map<int, int> ch[L];
bitset<676> havch[L];
int cnt[L], fail[L];

void init() {
	for (int i = 0; i <= tNode; ++i) {
		map<int, int>().swap(ch[i]);
		havch[i].reset();
		cnt[i] = fail[i] = 0;
	}
	tNode = 0;
}

void insert(vector<int> &S) {
	int u = 0;
	for (int x: S) {
		if (!havch[u][x]) {
			havch[u].set(x);
			ch[u][x] = ++tNode;
		}
		u = ch[u][x];
	}
	++cnt[u];
}

void build() {
	queue<int> Q; 
	for (auto [c, v]: ch[0]) Q.push(v);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (auto [c, v]: ch[u]) {
			int p = fail[u];
			while (p && !havch[p][c]) p = fail[p];
			if (havch[p][c]) fail[v] = ch[p][c];
			Q.push(v);
		}
		cnt[u] += cnt[fail[u]];
	//	cerr << u << ' ' << fail[u] << ' ' << cnt[u] << endl;
	}
}

long long query(vector<int> &T) {
	int u = 0; long long ans = 0;
	for (int x: T) {
		while (u && !havch[u][x]) u = fail[u];
		if (havch[u][x]) u = ch[u][x];
	//	cerr << u << endl;
		ans += cnt[u];
	}
	return ans;
}

long long ans[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> q; int max_diff = 0;
	for (int i = 1; i <= n; ++i) {
		string s[2];
		cin >> s[0] >> s[1]; int diff = 0;
		for (int j = 0; j < s[0].size(); ++j) {
			int x = s[0][j] - 'a';
			int y = s[1][j] - 'a';
			S[i].push_back(x * 26 + y);
			diff += (x != y);
		}
		opt[diff].push_back(i);
		max_diff = max(max_diff, diff);
	}

	for (int i = 1; i <= q; ++i) {
		string t[2];
		cin >> t[0] >> t[1]; int diff = 0;
		for (int j = 0; j < t[0].size(); ++j) {
			int x = t[0][j] - 'a';
			int y = t[1][j] - 'a';
			T[i].push_back(x * 26 + y);
			diff += (x != y);
		}
		qry[diff].push_back(i);
	}
	
	for (int k = 1; k <= max_diff; ++k) if (!opt[k].empty()) {
		init();
		for (int i: opt[k]) insert(S[i]);
		build();
		for (int i: qry[k]) ans[i] = query(T[i]);
	}	
	for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';

	return 0;
}