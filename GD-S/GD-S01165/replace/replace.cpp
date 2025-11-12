// chat to LUOGU 1058410 tell me you find me (I'm not goot at English)
// I'm a pupil, so I'm Newbie(Codeforces) (through i'm red name in luogu and my rating is 1014), so i think i only can get 2= or 3=. 
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define Pii pair<int, int>
#define fst first
#define snd second
#define pb push_back
#define endl '\n'

map<string, string> mp;

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		string s, t;
		cin >> s >> t;
		mp[s] = t;
	}
	while (q--) {
		string s, t;
		cin >> s >> t;
		LL ans = 0;
		for (auto i: mp) {
			for (int j = 0; j < s.size(); ++j) {
				if (s.substr(j, i.fst.size()) == i.fst) {
					string s2(s);
					s2.replace(j, i.fst.size(), i.snd);
					if (s2 == t) {
						++ans;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
// long long rp = LLONG_MAX!
