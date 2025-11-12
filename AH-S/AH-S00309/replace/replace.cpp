#include <bits/stdc++.h>
using namespace std;

int n, q;
string s[200010][3];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++)
		cin >> s[i][1] >> s[i][2];
	while(q --){
		int ans = 0;
		string a, b;
		cin >> a >> b;
		for(int i = 1; i <= n; i ++){
			int idx = 0;
			while(idx < (int)a.size() && a.find(s[i][1], idx) != string::npos){
//				cout << 1 << "\n";
				int k = a.find(s[i][1], idx);
				string s1 = "", s2 = "";
				if(k != 0) s1 = a.substr(0, k);
				if(k + s[i][1].size() != a.size()) s2 = a.substr(k + s[i][1].size());
				string now = s1 + s[i][2] + s2;
//				cout << now << '\n';
				if(now == b) ans ++;
				idx = k + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
