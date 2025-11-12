#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
constexpr int MAXN = 2e5 + 9;
int n, q, ans, sl1, sl2, beg, ed;
string s1, s2;
multimap<string, string> mp;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		beg = -1, ed = -1;
		sl1 = s1.size(), sl2 = s2.size();
		for(int i = 0; i < sl1; i++) {
			if(s1[i] != s2[i]) {
				if(beg == -1) beg = i;
				ed = i;
			}
		}
		string f1 = "", f2 = "";
		for(int i = beg; i <= ed; i++) {
			f1.push_back(s1[i]);
			f2.push_back(s2[i]);
		}
		mp.insert({f1, f2});
	}
	while(q--) {
		ans = 0;
		beg = -1, ed = -1;
		cin >> s1 >> s2;
		sl1 = s1.size(), sl2 = s2.size();
		if(sl1 != sl2) {
			cout << 0 << endl;
			continue;
		}
		for(int i = 0; i < sl1; i++) {
			if(s1[i] != s2[i]) {
				if(beg == -1) beg = i;
				ed = i;
			}
		}
		string f1 = "", f2 = "";
		for(int i = beg; i <= ed; i++) {
			f1.push_back(s1[i]);
			f2.push_back(s2[i]);
		}
		string nf1 = f1;
		for(auto i : mp) {
			if(i.fi.size() > sl1) continue; 
			nf1 = f1;
			auto it = f1.find(i.fi);
			if(it != -1) {
				nf1.replace(it, i.fi.size(), i.se);
				if(nf1 == f2) ans++; 
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
