#include <bits/stdc++.h>

#define ll long long
#define in(x) scanf ("%lld", &x)

using namespace std;

ll n;
ll m;
string s;
string ss;

struct node {
	string s1;
	string s2;
};

node a[1000005];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	in(n);
	in(m);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i].s1;
		cin >> a[i].s2;
	}
	while (m--) {
		ll ans = 0;
		cin >> s;
		cin >> ss;
		string t;
		string tt;
		//cout << s << endl;
		for (ll i = 0; i < s.length(); i++) {
			string t;
			string tt;
			for (ll j = 0; j < i; j++) {
				t += s[j];
			}
			for (ll j = 1; j <= n; j++) {
				bool flag = 1;
				for (ll k = 0; k < a[j].s1.length(); k++) {
					if (s[i + k] != a[j].s1[k]) {
						flag = 0;
					}
				}
				if (flag) {
					//cout << i << endl;
					//cout << j << endl;
					for (ll k = i + a[j].s1.length(); k < s.length(); k++) {
						tt += s[k];
					}
					//cout << t << endl;
					//string 
					//for (ll k = 0; k < i; k++) {
					//	
					//}
					string x = t + a[j].s2 + tt;
					//cout << x << endl;
					if (x == ss) {
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
