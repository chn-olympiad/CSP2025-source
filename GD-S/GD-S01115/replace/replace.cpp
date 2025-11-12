#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define int long long
const int inf = 0x3f3f3f3f3f3f3f3f;
const int mod1 = 1023200039, mod2 = 1023200039;
const int base = 23201;
struct Hsh {
	int v1, v2;
	Hsh() {v1 = 0, v2 = 0;}
	Hsh(int x, int y) {v1 = x, v2 = y;}
	Hsh friend operator* (Hsh x, int y) {
		return Hsh((x.v1 * y) % mod1, (x.v2 * y) % mod2);
	}
	Hsh friend operator+ (Hsh x, int y) {
		return Hsh((x.v1 + y) % mod1, (x.v2 + y) % mod2);
	}
	Hsh friend operator+ (Hsh x, Hsh y) {
		return Hsh((x.v1 + y.v1) % mod1, (x.v2 + y.v2) % mod2);
	}
	bool friend operator< (Hsh x, Hsh y) {
		if(x.v1 != y.v1) return x.v1 < y.v1;
		return x.v2 < y.v2;
	}
	bool friend operator> (Hsh x, Hsh y) {
		if(x.v1 != y.v1) return x.v1 > y.v1;
		return x.v2 > y.v2;
	}
};
Hsh pw[1000010];
Hsh gethsh(string s, int l, int r) {
	Hsh ans(0, 0);
	for(int i = l; i <= r; i++) {
		ans = ans * base + s[i];
	} 
	return ans;
}
int n, q; 
set<pair<pair<pair<Hsh, Hsh>, pair<Hsh, Hsh> >, int> > st;
map<pair<pair<Hsh, Hsh>, pair<Hsh, Hsh> >, int> mp;
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	pw[0] = Hsh(1, 1); for(int i = 1; i <= 1000000; i++) pw[i] = pw[i - 1] * base;
	scanf("%lld%lld\n", &n, &q);
	for(int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		int sz = s1.size();
		int l = 0, r = sz - 1;
		while(s1[l] == s2[l]) l++;
		while(s1[r] == s2[r]) r--;
//		cout << i << '\n';
//		cout << s1 << ' ' << s2 << '\n';
//		assert(st.find({{gethsh(s1, l, r), gethsh(s2, l, r)}, {gethsh(s1, 0, l - 1), gethsh(s1, r + 1, sz - 1)}}) == st.end());
		pair<pair<Hsh, Hsh>, pair<Hsh, Hsh> > hshshsh = {{gethsh(s1, l, r), gethsh(s2, l, r)}, {gethsh(s1, 0, l - 1), gethsh(s1, r + 1, sz - 1)}};
		if(mp.find(hshshsh) == mp.end()) mp[hshshsh] = 1;
		else mp[hshshsh]++;
	}
	for(map<pair<pair<Hsh, Hsh>, pair<Hsh, Hsh> >, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		st.insert(*it);
	}
	while(q--) {
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size()) {puts("0"); continue;}
		int sz = t1.size();
		
		int l = 0, r = sz - 1;
		while(t1[l] == t2[l]) l++;
		while(t1[r] == t2[r]) r--;
		Hsh hs1 = gethsh(t1, l, r), hs2 = gethsh(t2, l, r);
		set<Hsh> st2;
		Hsh hsuf(0, 0); st2.insert(hsuf);
		for(int i = r + 1; i <= sz - 1; i++) {
			hsuf = hsuf * base + t1[i];
			st2.insert(hsuf);
		}
		Hsh hpre(0, 0); int ans = 0;
			for(set<pair<pair<pair<Hsh, Hsh>, pair<Hsh, Hsh> >, int> >::iterator it = st.lower_bound({{{hs1, hs2}, {hpre, Hsh(-inf, -inf)}}, -inf}); 
			it != st.upper_bound({{{hs1, hs2}, {hpre, Hsh(inf, inf)}}, inf}); it++) {
				pair<pair<pair<Hsh, Hsh>, pair<Hsh, Hsh> >, int> piiii = *it;
				if(st2.find(piiii.first.second.second) != st2.end()) ans += piiii.second;
			}
		for(int i = l - 1; i >= 0; i--) {
			hpre = (hpre + pw[l - 1 - i] * t1[i]);
			for(set<pair<pair<pair<Hsh, Hsh>, pair<Hsh, Hsh> >, int> >::iterator it = st.lower_bound({{{hs1, hs2}, {hpre, Hsh(-inf, -inf)}}, -inf}); 
			it != st.upper_bound({{{hs1, hs2}, {hpre, Hsh(inf, inf)}}, inf}); it++) {
				pair<pair<pair<Hsh, Hsh>, pair<Hsh, Hsh> >, int> piiii = *it;
				if(st2.find(piiii.first.second.second) != st2.end()) ans += piiii.second;
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
