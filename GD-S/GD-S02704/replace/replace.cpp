#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;
pair<string, string> t[N];
pair<int, int> f[N];
bool IsIn;
int n, q;
void Init() {
	if(IsIn) return;
	IsIn = true;
	for(int i = 1; i <= n; i++) {
		int j;
		for(j = 1; j <= t[i].first.size(); j++) {
			if(t[i].first[j] == 'b') break;
		}
		f[i].first = j;
		for(j = 1; j <= t[i].second.size(); j++) {
			if(t[i].second[j] == 'b') break;
		}
		f[i].second = j;
	}
}
void B() {
	Init();
	int ans = 0;
	string w, to;
	cin >> w >> to;
	int fb, fb2;
	for(fb = 0; fb < w.size(); fb++) {
		if(w[fb] == 'b') break;
	}
	for(fb2 = 0; fb2 < to.size(); fb2++) {
		if(to[fb2] == 'b') break;
	}
	for(int i = 1; i <= n; i++) {
		if(f[i].first > fb) continue;
		if(fb2 - fb == f[i].second - f[i].first) ans++;
	}
	cout << ans << "\n";
}
void solve() {
	if(q != 1 && n >= 199999) {
		B();
		return;
	}
	int ans = 0;
	string c, w, cto, to;
	cin >> w >> cto;
	c = " " + w;
	to = " " + cto;
	for(int i = 1; i < c.size(); i++) {
		int te = c.size() - i;
		for(int j = 1; j <= n; j++) {
			if(te >= t[j].first.size()) {
				if(c.substr(i, t[j].first.size()) == t[j].first) {
					string ls = c;
					for(int k = 0; k < t[j].first.size(); k++) {
						ls[k + i] = t[j].second[k];
					}
					if(ls == to) ans++;
				}
			}
		}
	}
	cout << ans << "\n";
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> t[i].first >> t[i].second;
	}
	for(int i = 1; i <= q; i++) solve();
	
	return 0;
} 
