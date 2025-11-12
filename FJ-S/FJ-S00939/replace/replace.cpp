#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1, maxl = 5e6 + 1;
int nxt1[maxn + maxl], nxt2[maxn + maxl];
string s[maxn][2], t0, t1;
bool tree[maxl << 2];
void build(int u, int l, int r){
	if(l == r){
		tree[u] = (t0[l] == t1[l]);
		return;
	}int mid = (l + r) >> 1;
	build(u<<1, l, mid);
	build(u<<1|1, mid + 1, r);
	tree[u] = tree[u<<1] && tree[u<<1|1];
}
bool query(int u, int ul, int ur, int sl, int sr){
	if(sl <= ul && ur <= sr) return tree[u];
	if(sl > ur || sr < ul) return 1;
	int mid = (ul + ur) >> 1;
	return query(u<<1, ul, mid, sl, sr) && query(u<<1|1, mid + 1, ur, sl, sr);
}
int kmp(int x){
	int res = 0;
	string a = s[x][0] + "#" + t0, b = s[x][1] + "#" + t1;
	nxt1[0] = nxt2[0] = 1;
	for(int i = 1; i < b.size(); i++){
		int j = nxt2[i - 1];
		while(j > 1 && b[j] != b[i]) j = nxt2[j - 1];
		nxt2[i] = (b[j] == b[i] ? nxt2[j] + 1 : 0);
	}
	for(int i = 1; i < a.size(); i++){
		int j = nxt1[i - 1];
		while(j > 1 && a[j] != a[i]) j = nxt1[j - 1];
		nxt1[i] = (a[j] == a[i] ? nxt1[j] + 1 : 0);
		if(i > s[x][0].size() + 1)
			res += int(nxt1[i] == s[x][0].size() && query(1, 0, t0.size() - 1, 0, i - 2 * s[x][0].size() - 1) && query(1, 0, t0.size() - 1, i - s[x][0].size(), t0.size()) && nxt2[i] == s[x][1].size());
	}return res;
}
int main(){
	freopen("replace.in", "r", stdin); freopen("replace.out", "w", stdout);
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> s[i][0] >> s[i][1];
	while(q--){
		cin >> t0 >> t1;
		build(1, 0, t0.size() - 1);
		int ans = 0;
		for(int i = 1; i <= n; i++) ans += kmp(i);
		printf("%d\n", ans);
	}
	return 0;
}
