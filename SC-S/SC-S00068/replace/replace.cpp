#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int maxn = 5e6 + 10, H = 1317131;
int son[maxn][26], fail[maxn], lst[maxn], cnt = 0, ans = 0;
vector <int> ed[maxn];
string s1[maxn], s2[maxn], t1, t2;
ull hsh[maxn], pw[maxn] = {1}, hsht1[maxn], hsht2[maxn];
int idx(char c) {
	return c - 'a';
}
void gethsh(int id) {
	for(auto c : s1[id]) {
		hsh[id] *= H;
		hsh[id] += idx(c);
	}
}
void gethsht() {
	int pos = 1;
	for(auto c : t1) {
		hsht1[pos] = hsht1[pos - 1] * H + idx(c);
		++ pos;
	}
	pos = 1;
	for(auto c : t2) {
		hsht2[pos] = hsht2[pos - 1] * H + idx(c);
		++ pos;
	}
}
void insert(int id) {
	int p = 0;
	for(auto c : s2[id]) {
		int v = idx(c);
		if(!son[p][v]) son[p][v] = ++ cnt;
		p = son[p][v];
	}
	ed[p].push_back(id);
}
void bfs() {
	queue <int> q;
	for(int i = 0; i < 26; ++ i) if(son[0][i]) q.push(son[0][i]);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v = 0; v < 26; ++ v) {
			if(!son[u][v]) son[u][v] = son[fail[u]][v];
			else q.push(son[u][v]), fail[son[u][v]] = son[fail[u]][v];
			if(ed[fail[u]].size()) lst[u] = fail[u];
			else lst[u] = lst[fail[u]];
		}
	}
}
void check(int pos, int id) {
	//cerr << "!!!" << pos << " " << id << "\n";
	
	if(hsht1[pos - s1[id].size()] != hsht2[pos - s2[id].size()]) return;
	
	//cerr << "###" << hsht1[pos - s1[id].size()] << " " <<  hsht2[pos - s2[id].size()] << "\n";
	if(hsht1[pos] - hsht1[pos - s1[id].size()] * pw[s1[id].size()] != hsh[id]) return;
	if(hsht1[t1.size()] - hsht1[pos] * pw[t1.size() - pos] != hsht2[t2.size()] - hsht2[pos] * pw[t2.size() - pos]) return;
	++ ans;
}
void cal(int u, int pos) {
	while(u) {
		for(auto v : ed[u]) check(pos, v);
		u = lst[u];
	}
}
void query() {
	int p = 0, pos = 1; ans = 0;
	for(auto c : t2) {
		int v = idx(c);
		p = son[p][v];
		//cerr << "@@@" << p << "\n";
		cal(p, pos);
		++ pos;
	}
	cout << ans << "\n";
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i < maxn; ++ i) pw[i] = pw[i - 1] * H;
	for(int i = 1; i <= n; ++ i) cin >> s1[i] >> s2[i], insert(i), gethsh(i);
	bfs();
	for(int i = 1; i <= q; ++ i) {
		cin >> t1 >> t2;
		if(t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		gethsht();
		query();
	}
}
/*
3 1
a b
b c
c d
aa b
*/