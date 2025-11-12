#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N = 2e5 + 5, S = 5e6 + 5;
const int Base1 = 1331, Base2 = 2333;
int n, q;
ull p1[S], p2[S], h1[S], h2[S];
inline ull Hash1(string &s){
	ull res = 0;
	for(char c: s) res = res * Base1 + c;
	return res;
}
inline ull Hash2(string &s){
	ull res = 0;
	for(char c: s) res = res * Base2 + c;
	return res;
}
inline ull Hash(ull a, ull b){
	return (a << 11) ^ (a >> 7) ^ (b << 13) ^ (b >> 5);
}
inline ull get_hash1(int l, int r){
	return h1[r] - h1[l-1] * p1[r-l+1];
}
inline ull get_hash2(int l, int r){
	return h2[r] - h2[l-1] * p2[r-l+1];
}
unordered_map<ull, int> s;
set<int> lens;
signed main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> q; p1[0] = p2[0] = 1;
	for(int i=1; i<S; i++){
		p1[i] = p1[i-1] * Base1;
		p2[i] = p2[i-1] * Base2;
	}
	for(int i=1; i<=n; i++){
		string s1, s2; cin >> s1 >> s2;
		s[Hash(Hash1(s1), Hash2(s2))]++;
		lens.insert(s1.size());
	}
	while(q --> 0){
		string t1, t2; cin >> t1 >> t2;
		int m = t1.size(), ans = 0;
		t1 = " " + t1, t2 = " " + t2;
		h1[0] = h2[0] = 0;
		for(int i=1; i<=m; i++){
			h1[i] = h1[i-1] * Base1 + t1[i];
			h2[i] = h2[i-1] * Base2 + t2[i];
		}
		int l = 1, r = m;
		if(t1 == t2) l = 1, r = 0;
		else{
			while(t1[l] == t2[l]) l++;
			while(t1[r] == t2[r]) r--;
		}
		for(int len: lens){
			if(len < r - l + 1) continue;
			for(int i=max(len, r); i<=m; i++){
				ull hsh1 = get_hash1(i - len + 1, i);
				ull hsh2 = get_hash2(i - len + 1, i);
				ull tmp = Hash(hsh1, hsh2);
				if(s.count(tmp)) ans += s[tmp];
//				cout << len << ' ' << i << ' ' << hsh1 << ' ' << hsh2 << ' ' << ans << endl;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
2 1
12341 12561
34 56
12341 12561
*/
