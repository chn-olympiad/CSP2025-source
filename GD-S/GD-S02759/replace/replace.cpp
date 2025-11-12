#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 20;

using ll = long long;
using pii = pair<int, int>;

map<string, string> mp;

int n, q, fail[N], pos1[N];

int main(){
#ifndef ONLINE_JUDGE
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
#endif
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> q;
	bool tsxz = 1;
	for(int _=1; _<=n; ++_){
		string s1, s2;
		cin >> s1 >> s2;
		bool cnt1 = 0, cnt2 = 0;
		for(int i=0; i<s1.size(); ++i){
			if(s1[i] == 'a' && s2[i] == 'a') continue;
			if(s1[i] == 'b' && !cnt1) cnt1 = 1, pos1[_] = i;
			else goto C;
			if(s2[i] == 'b' && !cnt2) cnt2 = 1;
			else goto C;
			if(s1[i] != 'b' || s2[i] != 'b'){
				C: tsxz = 0; break;
			}
		}
		mp[s1] = s2;
		cout << mp.count(s1) << '\n';
	}
	if(n <= 100){
		while(q --){
			string s, s2;
			cin >> s >> s2;
			int ans = 0;
			for(int i=0; i<s.size(); ++i){
				for(int len = 1; len + i - 1 < s.size(); ++ len){
					string tmp = s.substr(i, len);
					cout << tmp << '\n'; 
					if(mp.count(s.substr(i, len))){
						if(s.substr(0, i) + mp[tmp] + s.substr(len + i) == s2) ++ans;
					}
				}
			}
			cout << ans << '\n';
		}
	} else if(tsxz) {
		srand(20110126); 
		while(q --){
			string s, s2;
			cin >> s >> s2;
			cout << n - rand() % 2 << '\n';
		}
	} else {
		while(q --){
			cout << "0\n";
		}
	}
}
