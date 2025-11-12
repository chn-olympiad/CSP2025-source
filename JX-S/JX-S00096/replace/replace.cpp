#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 5;
constexpr int M = 5e6 + 5;

int n, m;
map<string, map<string, int> > mp;
string a, b;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		mp[a][b]++;
	}
	
	while (m--) {
		cin >> a >> b;
		
		if (a.size() != b.size()) {
			cout << "0\n";
			continue;
		}
		
		int limit_l = -1, limit_r = -1;
		
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) {
				if (limit_l == -1) limit_l = i;
				else limit_r = i;
			}
		}
		
		if (limit_r == -1) limit_r = limit_l;
		
		string s = "", t = "";
		for (int i = limit_l + 1; i <= limit_r - 1; i++) {
			s += a[i];
			t += b[i];
		}
		
		long long answer = 0;
		
		string pre_s = "", pre_t = "";
		for (int l = limit_l; l >= 0; l--) {
			pre_s += a[l];
			pre_t += b[l];
			
			string suf_a = "", suf_b = "";
			for (int r = limit_r; r < a.size(); r++) {
				suf_a += a[r];
				suf_b += b[r];
				
				string _s = pre_s;
				string _t = pre_t;
				
				reverse(_s.begin(), _s.end());
				reverse(_t.begin(), _t.end());
				
				string _a = _s + s + suf_a;
				string _b = _t + t + suf_b;
				
				// cout << _a << " " << _b << "\n";
				
				if (mp.count(_a) != 0 && mp[_a].count(_b) != 0) {
					answer += mp[_a][_b];
				}
			}
		}
		
		cout << answer << "\n";
	}
	
	return 0;
}
