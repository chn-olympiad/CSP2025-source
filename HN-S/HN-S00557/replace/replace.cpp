#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1[100005], s2[100005], t1, t2;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	while(q--){
		cin >> t1 >> t2;
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			int p = 0, x = 0;
			while(t1.substr(p).find(s1[i]) != string::npos){
				int pos = t1.substr(p).find(s1[i]) + x;
				string a = t1.substr(0, pos), b = s2[i], c = t1.substr(pos + s1[i].size());
				if(a + b + c == t2) cnt++;
				p = pos + 1;
				x = pos + 1;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
