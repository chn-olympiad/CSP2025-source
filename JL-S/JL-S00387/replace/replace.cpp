#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10, K = 1e5;
int trie[N][30], cnt[N], idx, d[N], res[N];
string s1[N], s2[N], t1, t2;
int n, q, flag;
vector<int> V[N];
vector<pair<int, int> > mp[N];
bool check(int l, int r, int j) {
    string t = t1;
	for(int i = l; i <= r; i ++ ) t[i] = s2[j][i - l];
	return t == t2;
}
void init(int p) {
	int p1 = 0, p2 = 0, d;
	for(int i = 0; i < s1[p].length(); i ++ ) if(s1[p][i] == 'b') p1 = i;
	for(int i = 0; i < s2[p].length(); i ++ ) if(s2[p][i] == 'b') p2 = i; d = p1 - p2;
	if(!mp[d + K].size()) return ;
	for(int i = 0; i < mp[d + K].size(); i ++ ) {
		if(mp[d + K][i].second <= p1) res[mp[d + K][i].first] ++ ; return ;
	}
}
void insert(string s, int p) {
	int u = 0;
	for(int i = 0; i < s.length(); i ++ ) {
        if(s[i] != 'a' && s[i] != 'b') flag = 1;
		int v = s[i] - 'a';
		if(!trie[u][v]) trie[u][v] = ++ idx;
		u = trie[u][v];
	}
	cnt[u] ++ ; V[u].push_back(p);
}
int query(int p) {
	int u = 0, res = 0;
	for(int i = p; i < t1.length(); i ++ ) {
		int v = t1[i] - 'x';
		if(!trie[u][v]) return res;
		u = trie[u][v];
		if(cnt[u]) {
			for(int j = 0; j < V[u].size(); j ++ ) if(check(p, i, V[u][j])) res += cnt[u];
		}
	}
	return res;
}
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(false); cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++ ) cin >> s1[i] >> s2[i], insert(s1[i], i);
	if(flag) {
        for(int i = 1; i <= q; i ++ ) {
            cin >> t1 >> t2; int res = 0;
            if(t1.length() != t2.length()) { cout << 0 << '\n'; continue; }
            for(int j = 0; j < t1.length(); j ++ ) res += query(j);
            cout << res << '\n';
        }
	}
	else {
        for(int i = 1; i <= q; i ++ ) {
        	cin >> t1 >> t2;
        	if(t1.length() != t2.length()) { cout << 0 << '\n'; continue; }
        	int p1 = 0, p2 = 0;
        	for(int j = 0; j < t1.length(); j ++ ) if(t1[j] == 'b') p1 = j;
        	for(int j = 0; j < t2.length(); j ++ ) if(t2[j] == 'b') p2 = j;
        	mp[p1 - p2 + K].push_back({i, p1});
        }
        for(int i = 1; i <= n; i ++ ) init(i);
       	for(int i = 1; i <= q; i ++ ) cout << res[i] << '\n';
	}
	return 0;
}
