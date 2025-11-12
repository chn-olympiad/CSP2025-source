#include <bits/stdc++.h>
using namespace std;
string s1[200010], s2[200010];
int n, q;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i=1; i<=n; i++){
		cin >> s1[i] >> s2[i];
	}
	string t1, t2;
	int cnt;
	while (q--){
		cnt = 0;
		cin >> t1 >> t2;
		for (int i=1; i<=n; i++){
			if (int(t1.find(s1[i]))!=-1){
				int pos = t1.find(s1[i]);
				string t1a = t1.substr(0, pos) + s2[i] + t1.substr(pos + s1[i].size(), t1.size() - (pos + s1[i].size()));
//				cout << t1 << " " << s1[i] << " " << t1a << "\n";
				if (t1a == t2) cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
