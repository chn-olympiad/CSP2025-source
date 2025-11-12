#include <bits/stdc++.h>
#define ft first
#define sd second
using namespace std;

const int N = 2e5 + 5;
int n, q;
unordered_map<string, bool> mp;
string getlr(string s,int l,int r) {
	string ret;
	for(int i = l; i <= r; ++i) ret.push_back(s[i]);
	return ret;
}
vector<pair<int,pair<int,int>>> g;
void specialtestB() {
	while(q--) {
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		int ans = 0;
		int l = 0, r = 0;
		int l1 = t1.size() - 1;
		for(int j = 0; j <= l1; ++j) 
			if(t1[j] != 'a') l = j;
		for(int j = 0; j <= l1; ++j) 
			if(t2[j] != 'a') r = j;
		if(r < l) swap(l, r);
		for(auto v : g) {
			int len = v.ft;
			int lt = v.sd.ft, rt = v.sd.sd;
			if(len != r - l) continue;
			if(l < lt || r + rt > l1) continue;
			++ans;
		}
		cout << ans <<"\n";
	}
	return ;
}
void solve() {
	cin >> n >> q;
	bool f = 1;
	for(int i = 1; i <= n; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		int sp = 0, l = 0, r = 0;
		int l1 = s1.size();
		for(int j = 0; j < l1; ++j) {
			if(s1[j] != 'a') ++sp, l = j;
		}f &= (sp == 1);
		sp = 0;
		for(int j = 0; j < l1; ++j) {
			if(s2[j] != 'a') ++sp, r = j;
		}f &= (sp == 1);
		if(r < l) swap(l, r);
		if(f && mp.find(string(s1 + " " + s2)) == mp.end()) g.push_back({r - l,{l, l1 - 1 - r}});
		mp[string(s1 + " " + s2)] = 1;
		
	}
	if(f) {
		specialtestB();
		return ;
	}
	while(q--) {
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		int l = 0, r = t2.size() - 1;
		while(t1[l] == t2[l]) ++l;
		while(t1[r] == t2[r]) --r;
		int ans = 0;
		for(int i = 0; i <= l; ++i) {
			for(int j = r; j < t2.size(); ++j) {
				if(mp.find(getlr(t1, i, j) + " " + getlr(t2, i, j)) != mp.end()) ++ans;
			}
		}
		cout << ans << "\n";
	}
	return ;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
