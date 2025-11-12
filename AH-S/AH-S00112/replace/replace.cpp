#include <bits/stdc++.h>
using namespace std;
int n, q;
string s1[200001], s2[200001];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	for(int i = 1; i <= q; i++) {
		int ans = 0;
		string q1, q2;
		cin >> q1 >> q2;
		if(q != 1) cout << "0" << endl;
		else {
			for(int j = 1; j <= n; j++) {
				if(q1.find(s1[j])) {
					if(q1 == q2) ans++;
				}
			}
			cout << ans << endl;
		} 
	}
	return 0;
}
