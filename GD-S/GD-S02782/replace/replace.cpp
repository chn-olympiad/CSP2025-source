#include <iostream>
#include <unordered_map>
#include <string>
#include <cstring>
#include <map>
#define endl '\n'
#define pii pair<int, int>
using namespace std;

const int N = 1e6 + 5;

unordered_map<string, string> mp;
map<pii, int> mp2;
string hou[N];
int vis[500];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	char teshu;
	bool flag2 = 1;
	for(int i = 1; i <= n; i++) {
		string s, str;
		cin >> s >> str;
		mp[s] = str;
		if(i == 1) {
//			cout << "debug" << endl;
			for(int j = 0; j < s.size(); j++) {
				vis[s[j]]++;
			}
			bool flag = 0;
			for(char j = 'a'; j <= 'z'; j++) {
				if(vis[j] != s.size() - 1 && vis[j]) {
					teshu = j;
					if(flag) {
						flag2 = 0;
						break;
					}
					flag = 1;
				}
			}
		}
		if(flag2) {
			int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
			for(int j = 0; j < s.size(); j++) {
				if(s[j] == teshu) {
					cnt1 = j, cnt2 = s.size() - j;
					break;
				}
			}
			for(int j = 0; j < str.size(); j++) {
				if(str[j] == teshu) {
					cnt3 = j, cnt4 = str.size() - j;
					break;
				}
			}
			mp2[{cnt3 - cnt1, cnt4 - cnt2}]++;
		}
	}
	int sum222 = 0;
	while(q--) {
		string s, t;
		cin >> s >> t;
		sum222 += s.size() + t.size();
		if(sum222 <= 2500 || q == 1) {
			hou[s.size()] = "";
			for(int i = s.size() - 1; i >= 0; i--) hou[i] = s[i] + hou[i + 1];
			string tmp = "";
			int cnt = 0;
			for(int i = 0; i < s.size(); i++) {
				string str = "";
				for(int j = i; j < s.size(); j++) {
					str += s[j];
					if(mp.count(str)) {
						if(tmp + mp[str] + hou[j + 1] == t) cnt++;
					}
				} 
				tmp += s[i];
			}
			cout << cnt << endl;
		}
		else {
//			cnt2222++;
			if(flag2) {
				int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
				for(int j = 0; j < s.size(); j++) {
					if(s[j] == teshu) {
						cnt1 = j, cnt2 = s.size() - j;
						break;
					}
				}
				for(int j = 0; j < t.size(); j++) {
					if(t[j] == teshu) {
						cnt3 = j, cnt4 = t.size() - j;
						break;
					}
				}
//				cerr << s << endl;
//				if(cnt2222 == 12) cerr << cnt1 << ' ' << cnt2 << ' ' << cnt3 << ' ' << cnt4 << ' ' << mp2[{cnt3 - cnt1, cnt4 - cnt2}] << endl;
				cout << mp2[{cnt3 - cnt1, cnt4 - cnt2}] << endl;
			}
		}
	}
	return 0;
}
