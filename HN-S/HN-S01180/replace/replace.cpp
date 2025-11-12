#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const int P = 114917813;
const int MAX_N = 2e6 + 50;

int n, q;
unordered_map<ull, int> mp[MAX_N];

template<int base>
class strHash {
public:	
	strHash(string s) {
		pw.assign(s.size() + 1, 1);
		hs.assign(s.size() + 1, 0);
		for (int i = 1; i <= s.size(); i++) {
			pw[i] = pw[i - 1] * base;
			hs[i] = hs[i - 1] * base + s[i - 1]; 
		}
	}
	
	ull operator () () const {return hs.back(); }
	
	ull operator () (int l, int r) const {
		return hs[r] - hs[l - 1] * pw[r - l + 1];
	}
	
private:
	vector<ull> pw, hs;
};

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		strHash<131> hs1(s1), hs2(s2);
		int len = s1.size();
		mp[len][hs1() * P + hs2()]++;
 	}
 	
 	for (string t1, t2; q--; ) {
 		cin >> t1 >> t2;
 		int l = 0, r;
 		int len = t1.size();
 		for (int i = 1; i <= len; i++)
 			if (t1[i - 1] != t2[i - 1]) {
 				if (!l) l = i;
 				r = i;
			}
		strHash<131> hs1(t1), hs2(t2);
		long long ans = 0;
		for (int i = 1; i <= l; i++)
			for (int j = r; j <= len; j++) {
				ull val = hs1(i, j) * P + hs2(i, j);
				ans += mp[j - i + 1][val];
			}
		cout << ans << '\n';
	}
	return 0;
}
