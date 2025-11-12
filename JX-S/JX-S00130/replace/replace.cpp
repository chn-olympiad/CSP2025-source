#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, q;

struct AC {
	int nxt[(int)5e6+10][26], tot = 1;
	int cnt[(int)5e6 + 10], fail[(int)5e6 + 10], len[(int)5e6 + 10];
	void ins(const string &a) {
		int p = 1, sz = 0;
		for(char c : a) {
			if(!nxt[p][c - 'a']) nxt[p][c - 'a'] = ++tot;
			p = nxt[p][c - 'a'];
			len[p] = ++sz;
		}
		++cnt[p];
		len[p] = a.size();
	}
	queue<int> q;
	void build() {
		for(int i = 0; i < 26; i++) { if(nxt[1][i]) q.push(nxt[1][i]); else nxt[1][i] = 1; }
		while(!q.empty()) {
			int x = q.front(); q.pop();
			for(int i = 0; i < 26; i++) {
				if(nxt[x][i]) {
					fail[nxt[x][i]] = nxt[fail[x]][i], q.push(nxt[x][i]);
				} else nxt[x][i] = nxt[fail[x]][i];
			}
		}
	}
	int solve(const string &a, int l, int r) {
		int p = 1, ans = 0;
		for(int i = 0; i < a.size(); i++) {
			int v = a[i] - 'a';
			p = nxt[p][v];
			if(!p) break;
			if(i >= r) {
				int t = p;
				while((len[t]) >= (- l + 1 + i)) ans+=cnt[t], t = fail[t];
			}
		}
		return ans;
	}
} ac;
string a, b, c;

void solve() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) {
		cin>>a>>b;
		c.clear();
		for(int i = 0; i < a.size(); i++) c += a[i], c += b[i];
		ac.ins(c);
	}
	ac.build();
	for(int i = 1; i <= q; i++) {
		cin>>a>>b;
		if(a.size() != b.size()) {printf("0\n"); continue;}
		int l = a.size(), r = -1;
		for(int j = 0; j < a.size(); j++) if(a[j] != b[j]) l = min(l, j), r = max(r, j);
		c.clear();
		for(int j = 0; j < a.size(); j++) c += a[j], c += b[j];
		printf("%d\n", ac.solve(c, l*2, r*2));
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	solve();
}