#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull P = 131;
typedef pair<int, int> pii;
const int N = 5e6 + 5;
int n, q;
map<pii, int> mp;
struct trie{
	int tr[N][26], tot;
	int ins(string &s){
		int p = 0;
		for(int i = 0; i < s.size(); ++i){
			int x = s[i] - 'a';
			if(!tr[p][x]) tr[p][x] = ++tot;
			p = tr[p][x]; 
		}
		return p;
	}
}s, t;
struct hashe{
	ull hsh[N], pw[N];
	int m;
	void init(){
		pw[0] = P;
		for(int i = 1; i <= 5e6; ++i) pw[i] = pw[i - 1] * P;
	}
	void assign(string &a, int len){
		m = len;
		a = "#" + a;
		for(int i = 1; i <= len; ++i){
			int x = a[i] - 'a';
			hsh[i] = hsh[i - 1] * P + x;
		}
	}
	ull get(int l, int r){
		if(l > r) return 0; 
		return hsh[r] - pw[r - l] * hsh[l - 1];
	}
}u, v;
int main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	u.init(), v.init();
	for(int i = 1; i <= n; ++i){
		string a, b; cin >> a >> b;
		int x = s.ins(a), y = t.ins(b);
		mp[{x, y}]++;
	}
	while(q--){
		string f, g;
		cin >> f >> g;
		if(f.size() != g.size()){
			cout << 0 << '\n';
			continue;
		};
		int m = f.size(), ans = 0;
		u.assign(f, m), v.assign(g, m);
		for(int i = 1; i <= m; ++i){
			int p = 0, q = 0;
			if(u.get(1, i - 1) != v.get(1, i - 1)) continue;
			for(int j = i; j <= m; ++j){
				int x = f[j] - 'a', y = g[j] - 'a';
				p = s.tr[p][x], q = t.tr[q][y];
				if(!p || !q) break;
				if(u.get(j + 1, m) != v.get(j + 1, m)) continue;
				ans += mp[{p, q}];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

