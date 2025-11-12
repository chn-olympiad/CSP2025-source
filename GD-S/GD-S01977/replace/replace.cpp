#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, q;
	size_t s[200010], ss[200010], sss[200010];
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) {
		string ss1, ss2;
		cin >> ss1 >> ss2;
		
		size_t pos1 = ss1.find("b");
		size_t pos2 = ss2.find("b");
		s[i] = pos1;
		ss[i] = pos2;
		sss[i] = ss1.size();
	}
	
	while (q--) {
		int ans = 0;
		string s1, s2;
		cin >> s1 >> s2;
		
		size_t pos1 = s1.find("b");
		size_t pos2 = s2.find("b");
		for (int i = 1; i <= n; i++) {
			if (pos2 - pos1 == ss[i]-s[i] && s1.size() - pos1 >= sss[i] - s[i] && pos1 >= s[i]) {
				ans++;
				//cout << s[i] << endl;
			}
		}
		
		cout << ans << endl;//<< ' ' << pos2 << endl;
	}
	
	return 0;
}
