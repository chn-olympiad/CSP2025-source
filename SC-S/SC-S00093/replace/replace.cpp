#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;

#define int long long
int n, q;
struct work{
	string a;
	string b;
}w[200005];
string x1, x2;
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> w[i].a >> w[i].b;
	}
	while(q--) {
		int ans = 0;
		string s1,s2;
		cin >> s1 >> s2;
		x1 = s1, x2 = s2;
		if(s1.size() != s2.size()) {
			cout << 0 << endl;
			continue;
		}
		for(int i = 1; i <= n; ++i) {
			s1 = x1, s2 = x2;
			while(s1.find(w[i].a) <= s1.size() && !s1.empty()) {
				int num = 0;
				int e = s1.find(w[i].a);
				for(int j = e; j < e + w[i].b.size(); ++j) {
					s1[j] = w[i].b[num];
					num++;
				}
				if(s1 == s2) ans++;
				string l1 = "", l2 = "";
				for(int j = s1.find(w[i].a) + w[i].a.size(); j < s1.size(); ++j) {
					l1 += s1[j];
				}
				for(int j = s2.find(w[i].b) + w[i].b.size(); j < s2.size(); ++j) {
					l2 += s2[j];
				}
				s1 = l1;
				s2 = l2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
