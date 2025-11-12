#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 7, INF = 1e9 + 9;
const int p[2] = {3832131, 133831}, mod[2] = {998244353, INF};
int n, q;

struct N{
	vector<int> g[2], h[2];
	int sz;
	void add(string s){
		for(int i = 0; i < 2; i++){
			g[i] = {0}, h[i] = {1};
			for(int j = 0; j < s.size(); j++){
				g[i].push_back((g[i].back() * p[i] + s[j]) % mod[i]);
				h[i].push_back(h[i].back() * p[i] % mod[i]);
			}
		}
		sz = s.size();
	}
	pair<int, int> sum(int l, int r){
		if(!sz) return {-1, -1};
		int ans[2];
		for(int i = 0; i < 2; i++){
			ans[i] = (g[i][r] - g[i][l - 1] * h[i][r - l + 1] % mod[i] + mod[i]) % mod[i];
		}
		return {ans[0], ans[1]};
	}
}a[N], b[N], c[N], d[N], aa, bb, cc, dd;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		string s, t; cin >> s >> t;
		int mn = 1e18, mx = -1e18;
		for(int i = 0; i < s.size(); i++){
			if(s[i] != t[i]){
				mn = min(mn, i), mx = max(mx, i);
			}
		}
		if(mn == 1e18) continue;
		string s1, t1;
		for(int i = mn; i <= mx; i++) s1 += s[i], t1 += t[i];
		string s2, s3;
		for(int i = 0; i < mn; i++) s2 += s[i];
		for(int i = mx + 1; i < s.size(); i++) s3 += s[i];
		a[i].add(s1);
		b[i].add(t1);
		c[i].add(s2);
		d[i].add(s3);
	}
	while(q--){
		string s, t; cin >> s >> t;
		if(s.size() != t.size()){
			cout << "0\n"; continue;
		}
		int mn = 1e18, mx = -1e18;
		for(int i = 0; i < s.size(); i++){
			if(s[i] != t[i]){
				mn = min(mn, i), mx = max(mx, i);
			}
		}
		string s1, t1;
		for(int i = mn; i <= mx; i++) s1 += s[i], t1 += t[i];
		string s2, s3;
		for(int i = 0; i < mn; i++) s2 += s[i];
		for(int i = mx + 1; i < s.size(); i++) s3 += t[i];
		aa.add(s1);
		bb.add(t1);
		cc.add(s2);
		dd.add(s3);
		int cnt = 0;
		for(int j = 1; j <= n; j++){
			if(aa.sum(1, aa.sz) != a[j].sum(1, a[j].sz)) continue;
			if(bb.sum(1, bb.sz) != b[j].sum(1, b[j].sz)) continue;
			if(cc.sz < c[j].sz) continue;
			if(dd.sz < d[j].sz) continue;
			if(!c[j].sz || cc.sum(cc.sz - c[j].sz + 1, cc.sz) != c[j].sum(1, c[j].sz)) continue;
			if(!d[j].sz || dd.sum(1, d[j].sz) != d[j].sum(1, d[j].sz)) continue;
			++cnt;
		}
		cout << cnt << '\n';
	}
	return 0;
}
