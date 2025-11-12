#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;

struct node {
	string s1, s2;
} a[N], t[N];;

string t1, t2;

int n, m, cnt = 0;;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].s1 >> a[i].s2;
		
	}
	
	for (int i = 1; i <= m; ++i)
		cin >> t[i].s1 >> t[i].s2;
	
	
	for (int k = 1; k <= m; ++k) {
		cnt = 0;
		for (int i = 1; i <= n; ++i) { 
			int x = t[k].s1.find(a[i].s1);
			int j = 0;
			
			for (int l = x; l <= x + (int)a[i].s1.size(); ++l) {
				t[k].s1[l] = a[i].s1[j++];
			}
			
			if (t[k].s1 == t[k].s2)
				++cnt;
				 
		}
	
		cout << cnt << "\n";
	}	
	return 0;
}

// 1 1 abc ab dabcd dabcd
