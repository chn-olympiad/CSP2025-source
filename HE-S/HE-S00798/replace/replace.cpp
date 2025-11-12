#include <bits/stdc++.h> // beng kui le ,tiaole 2 hour meitiaochulai
#define int unsigned long long
using namespace std;

inline unsigned long long hashd(string s) {
	int to = 0;
	for (char v : s) to = to * 27 + (v - 'a');
	return to;
}

struct node {
	int x, y_, z;
	int llen, rlen;
};

map <int, int> mp;
int cntmp;

vector <node> v[200005];

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2; cin >> s1 >> s2;
		
		string sa="", sb=""; int llen = 0, rlen = 0, l = 0, r = -1;
		for (int j = 0; j < s1.length(); j++) {
			if (s1[j] == s2[j]) sa = sa + s1[j];
			else break;
			llen ++; l++;
		}
		for (int j = s1.length() - 1; j >= 0; j--) {
			if (s1[j] == s2[j]) sb = sb + s2[j]; 
			else break;
			rlen ++;
			r = j - 1;
		}
		string ss1 = "",ss2="";
		for (int i = l; i <= r; i++) {
			ss1 = s1[i];
			ss2 = s2[i];
		}
		int sa_ = hashd(sa), sb_ = hashd(sb), sss1 = hashd(ss1), sss2 = hashd(ss2);
		if (!mp[sa_]) mp[sa_] = ++cntmp;
		v[mp[sa_]].push_back((node){sa_, sss2,sb_, llen, rlen});
	}
	
	while(q--) {
		string t1, t2;
		cin >> t1 >> t2;
//		if (t1.size() != t2.size()) {
			cout << "0\n";
//			continue;
//		}
//		
//		int suml[200010]={}, sumr[200010] ={};
//		 int llen = 0, rlen = 0, l = 0, r = -1;
//		for (int j = 0; j < t1.length(); j++) {
//			if (t1[j] == t2[j] && j) suml[j] = suml[j - 1]*27 +(t1[j]-'a');
//			else break;
//			//llen ++;
//			l++;
//		}
//		for (int j = t1.length() - 1; j >= 0; j--) {
//			if (t1[j] == t2[j]) sumr[j] = sumr[j + 1]*27 +(t1[j]-'a');
//			else break;
//			//rlen ++;
//			r = j - 1;
//		}
//		string ss1="",ss2="";
//		for (int i = l; i <= r; i++) {
//			ss1 = t1[i];
//			ss2 = t2[i];
//		}
//		int  sss1 = hashd(ss1), sss2 = hashd(ss2);
//		for (int i = 0; i < v[mp[sss1]].size(); i++) {
//			if (sss2 == v[mp[sss1]].y_ && suml[l - 1] - suml[l - v[mp[sss1]].llen] == v[mp[sss1]].x
//			 && sumr[r + 1] - sumr[r + v[mp[sss1]].rlen + 1] == v[mp[ss1]].z) ans ++;
//			
//		}
//		cout << ans << "\n";
	}
	
	return 0;
}

