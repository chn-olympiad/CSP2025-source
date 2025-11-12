#include <bits/stdc++.h>
using namespace std;
string s[200005][3];
string t[200005][3];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> s[i][1] >> s[i][2];
	}
	for (int i = 1; i <= q; i++){
		cin >> t[i][1] >> t[i][2];
	}
	for (int i = 1; i <= q; i++){
		int ans = 0;
		cout << ans << endl;
	} 
	return 0;
} 






