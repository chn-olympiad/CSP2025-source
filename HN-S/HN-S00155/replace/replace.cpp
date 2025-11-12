#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int base = 13331;
int n, q, sz[5000005];
ll s1[5000005], s2[5000005], t1[5000005], t2[5000005], pw[5000005];
unordered_map<ll, ll> mp;
ll hsh(bool f, int l, int r){
	if(l > r) return 0ll;
	if(f) return t1[r] - t1[l - 1] * pw[r - l + 1];
	return t2[r] - t2[l - 1] * pw[r - l + 1];
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	pw[0] = 1;
	for(int i = 1; i <= 5000000; i++) pw[i] = pw[i - 1] * base;
	for(int i = 1; i <= n; i++){
		string s, t;
		cin >> s >> t;
		sz[i] = s.size();
		s = ' ' + s, t = ' ' + t;
		for(int j = 1; j < s.size(); j++){
			s1[i] = s1[i] * base + s[j];
			s2[i] = s2[i] * base + t[j];
		}
//		cerr << s1 << ' ' << s2 <<'\n';
		mp[s1[i]] = s2[i];
	}
	while(q--){
		string s, t;
		int ans = 0;
		cin >> s >> t;
		if(s.size() != t.size()){
			cout << "0\n";
			continue;
		}
		int l = s.size();
		s = ' ' + s, t = ' ' + t;
		for(int i = 1; i <= l; i++){
			t1[i] = t1[i - 1] * base + s[i];
			t2[i] = t2[i - 1] * base + t[i];
		}
		for(int i = 1; i <= l; i++){
			for(int k = 1; k <= n; k++){
				int j = i + sz[k] - 1;
				if(j > l) continue;
				ll h1 = hsh(1, i, j), h2 = hsh(0, i, j);
//				if(i == 3 && j == 4) cerr << h1 << ' ' << h2 << '\n';
				if(h1 == s1[k] && h2 == s2[k]){
					ll x = hsh(1, 1, i - 1), x2 = hsh(1, j + 1, l);
					ll y = hsh(0, 1, i - 1), y2 = hsh(0, j + 1, l);
					if(x == y && x2 == y2) ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
