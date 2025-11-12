#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	string s = "123";
//	cout << s.find("1") << endl;
	int n, _;
	cin >> n >> _;
	vector<pair<string, string>> a(n);
	for (auto &[i, j] : a) cin >> i >> j;
	while (_ --) {
		string x, y;
		cin >> x >> y;
		if (x.size() != y.size()) {
		   cout << 0;
		   continue;
        }
        int end_w = x.size();
        for (int i = 0; i < x.size(); i ++)
        	if (x[i] != y[i])
        	   end_w = i + 1;
 	    end_w = min(end_w, (int)x.size());
		int ans = 0;
		for (int i = 0; i < end_w; i ++)
			for (int j = 0; j < n; j ++) {
				string p = a[j].first;
				if (i + p.size() > x.size() || p[0] != x[i])
				   continue;
 			    if (p != x.substr(i, p.size())) continue;
				if (x.substr(0, i) + a[j].second + (i + p.size() == x.size() ? "" : x.substr(i + p.size())) == y)
				   ans ++;
// 			    cout << x.substr(0, i) + a[j].second + (i + p.size() == x.size() ? "" : x.substr(i + p.size() + 1));
			}
	    cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
xabcx xadex
ab
cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
