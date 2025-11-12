#include <bits/stdc++.h>
using namespace std;
int fail[2][2500005], son[2][2500005][26], dep[2][2500005], in[2], n, q, dfn[2500005], siz[2500005], s[2500005], tot, d[2500005], lr[2][2500005], bl[2500005], cnt;
long long ans[200005];
string s1, s2;
vector<int> vec[2][2500005];
struct node{
	int x, id;
};
vector<node> v1[2][2500005];
vector<int> v0[2500005];

int built(string s, int k){
	int len = s.size(), pos = 1;
	for( int i = 0; i < len; i++ ){
		if(!son[k][pos][s[i] - 'a']){
			son[k][pos][s[i] - 'a'] = ++in[k];
			dep[k][in[k]] = dep[k][pos] + 1;
		}
		pos = son[k][pos][s[i] - 'a'];
	}
	return pos;
}
void bfs(int k){
	int hd = 1, tl = 0;
	for( int i = 0; i < 26; i++ ){
		if(son[k][1][i]){
			fail[k][son[k][1][i]] = 1;
			vec[k][1].emplace_back(son[k][1][i]);
			s[++tl] = son[k][1][i];
		}
		else son[k][1][i] = 1;
	}
	while(hd <= tl){
		int t = s[hd++];
		for( int i = 0; i < 26; i++ ){
			if(son[k][t][i]){
				fail[k][son[k][t][i]] = son[k][fail[k][t]][i];
				vec[k][fail[k][son[k][t][i]]].emplace_back(son[k][t][i]);
				s[++tl] = son[k][t][i];
			}
			else son[k][t][i] = son[k][fail[k][t]][i];
		}
	}
	return;
}
void dfs1(int x){
	siz[x] = 1;
	dfn[x] = ++tot; 
	for( int i : vec[1][x] ){
		dfs1(i);
		siz[x] += siz[i];
	}
	return;
}
void modify(int x, int val){
	for( int i = x; i <= tot; i += i & (-i) ) s[i] += val; 
	return;
}
int query(int x){
	int sum = 0;
	for( int i = x; i; i -= i & (-i) ) sum += s[i];
	return sum;
}
void solve(int x){
	for( int i : v0[x] ){
		modify(dfn[i], 1);
		modify(dfn[i] + siz[i], -1);
	}
	for( node i : v1[0][x] ) ans[abs(i.id)] += (i.id > 0 ? 1 : -1) * query(dfn[i.x]);
	for( int i : vec[0][x] ) solve(i);
	for( int i : v0[x] ){
		modify(dfn[i], -1);
		modify(dfn[i] + siz[i], 1);
	}
	return;
}
void dfs2(int x, int k){
	s[d[x]] = x;
	for( node i : v1[k][x] ){
		int l = 1, r = d[x];
		while(l < r){
			int mid = (l + r + 1) >> 1;
			if(dep[k][s[mid]] <= i.x) l = mid;
			else r = mid - 1;
		}
		lr[k][i.id] = s[l];
	}
	for( int i : vec[k][x] ){
		d[i] = d[x] + 1;
		dfs2(i, k);
	}
	return;
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	in[0] = in[1] = 1;
	for( int i = 1; i <= n; i++ ){
		cin >> s1 >> s2;
		v0[built(s1, 0)].emplace_back(built(s2, 1));
	}
	bfs(0), bfs(1);
	memset(s, 0, sizeof(s));
	dfs1(1);
	for( int op = 1; op <= q; op++ ){
		cin >> s1 >> s2;
		int len = s1.size();
		int l = len, r = 0;
		for( int i = 0; i < len; i++ ){
			if(s1[i] != s2[i]){
				l = min(l, i);
				r = max(r, i);
			}
		}
		int p0 = 1, p1 = 1;
		for( int i = 0; i < len; i++ ){
			p0 = son[0][p0][s1[i] - 'a'];
			p1 = son[1][p1][s2[i] - 'a'];
			if(i < r) continue;
			if(i - dep[0][p0] >= l) continue;
			if(i - dep[1][p1] >= l) continue;
			bl[++cnt] = op;
			fail[0][cnt] = p0, fail[1][cnt] = p1;
			v1[0][p0].push_back({i - l, cnt});
			v1[1][p1].push_back({i - l, cnt});
		}
	}
	d[1] = 1;
	dfs2(1, 0), dfs2(1, 1);
	memset(s, 0, sizeof(s));
	for( int i = 1; i <= in[0]; i++ ) v1[0][i].clear();
	for( int i = 1; i <= cnt; i++ ){
		v1[0][lr[0][i]].push_back({lr[1][i], bl[i]});
		v1[0][lr[0][i]].push_back({fail[1][i], -bl[i]});
		v1[0][fail[0][i]].push_back({lr[1][i], -bl[i]});
		v1[0][fail[0][i]].push_back({fail[1][i], bl[i]});
	}
	solve(1);
	for( int i = 1; i <= q; i++ ) cout << ans[i] << '\n';
	return 0;
}
