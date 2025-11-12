#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
string get(string s, int l, int r) {
	string res;
	for(int i = l; i <= r; i++) res += s[i];
	return res;
}
string calc(string s, int l, int r, string a) {
	string res;
	for(int i = 0; i < l; i++) {
		res += s[i];
	}
	res += a;
	for(int i = r; i < s.size(); i++) {
		res += s[i];
	}
	return res;
}
void work() {
	int n, q;
	cin >> n >> q;
	vector<string> a(n+1), b(n+1);
	vector<int> sz(n+1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		sz[i] = a[i].size();
	} 
	while(q--) {
		string p, q;
		cin >> p >> q;
		ll ans = 0, len = p.size();
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j + sz[i] - 1 <= n; j++) {
				if(get(p, j, j + sz[i] - 1) == a[i] && calc(p, j, j + sz[i]-1, b[i]) == q) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--) {
		work();
	}
	return 0;
}
