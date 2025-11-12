#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e6 + 1;

int n, q, add[MAXN], L[MAXN], id[MAXN][2];
string s[MAXN][2];
map<string, string> mp1;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	bool flag = true;
	for(int i = 1; i <= n; i++) {
		cin >> s[i][0] >> s[i][1];
		mp1[s[i][0]] = s[i][1];
		map<char, int> mp;
		for(int j = 0; j < s[i][0].size(); j++) {
			mp[s[i][0][j]]++;
		}
		flag &= (mp['b'] == 1 && mp['a'] == s[i][0].size() - 1);
		mp.clear();
		for(int j = 0; j < s[i][1].size(); j++) {
			mp[s[i][1][j]]++;
		}
		flag &= (mp['b'] == 1 && mp['a'] == s[i][1].size() - 1);
		L[i] = s[i][0].size();
	}
	if(flag) {
		for(int i = 1; i <= n; i++) {
			int id1 = 0, id2 = 0;
			for(int j = 0; j < s[i][0].size(); j++) {
				if(s[i][0][j] == 'b') {
					id1 = j;
					id[i][0] = j;
					break;
				}
			}
			for(int j = 0; j < s[i][1].size(); j++) {
				if(s[i][1][j] == 'b') {
					id2 = j;
					id[i][1] = j;
					break;
				}
			}
			add[i] = id2 - id1;
		}
		while(q--) {
			string T1, T2;
			cin >> T1 >> T2;
			int id1 = 0, id2 = 0;
			for(int j = 0; j < T1.size(); j++) {
				if(T1[j] == 'b') {
					id1 = j;
					break;
				}
			}
			for(int j = 0; j < T2.size(); j++) {
				if(T2[j] == 'b') {
					id2 = j;
					break;
				}
			}
			cout << id1 << " " << id2 << "\n";
			int res = 0;
//			for(int i = 1; i <= n; i++) {
//				if(L[i] <= T1.size() && ) {
//					res += (add[i] + id1 == id2);
//				}
//			}
			cout << res << "\n";
		}
	}
	else {
		while(q--) {
			string T1, T2;
			cin >> T1 >> T2;
			if(T1.size() != T2.size()) {
				cout << 0 << "\n";
				continue;
			}
			int l = 0, r = T1.size() - 1;
			for(int i = 0; i < T1.size(); i++) {
				if(T1[i] != T2[i]) {
					break;
				}
				l = i + 1;
			}
			for(int i = T1.size() - 1; i >= 0; i--) {
				if(T1[i] != T2[i]) {
					break;
				}
				r = i - 1;
			}
			int res = 0;
			for(int i = 0; i <= l; i++) {
				string now1 = "", now2 = "";
				for(int j = i; j < r; j++) {
					now1 += T1[j];
					now2 += T2[j];
				}
				for(int j = r; j < T1.size(); j++) {
					now1 += T1[j];
					now2 += T2[j];
//					cout << now1 << " " << now2 << "\n";
					if(mp1[now1] == now2) {
						res++;
					}
				}
			}
			cout << res << "\n";
		}
	}
	return 0;
}
