#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n , q , a1[200010] , a2[200010] , len[200010] , b1[5000010] , b2[5000010] , poww[5000010] , ans;
string s , s1 , s2; 
map <int , int> m;
int haxi (string s) {
	int ans = 0;
	for (int i = 0;i < s.size();i ++) {
		ans = ans * 131 + s[i];
	}
	return ans;
}
signed main () {
	freopen ("replace.in" , "r" , stdin);
	freopen ("replace.out" , "w" , stdout); 
	ios::sync_with_stdio (0);
	cin.tie (0); cout.tie (0);
	cin >> n >> q;
	poww[0] = 1;
	for (int i = 1;i <= 5000000;i ++) {
		poww[i] = poww[i - 1] * 131;
	}
	for (int i = 1;i <= n;i ++) {
		cin >> s;
		a1[i] = haxi (s);
		cin >> s;
		a2[i] = haxi (s);
		len[i] = s.size ();
		m[a1[i]] = a2[i];
		cout << a1[i] <<' ' << a2[i] << '\n';
	}
	while (q --) {
		ans = 0;
		cin >> s1 >> s2;
		int siz = s1.size ();
		s1 = ' ' + s1; s2 = ' ' + s2;
		for (int i = 1;i <= siz;i ++) {
			b1[i] = b1[i - 1] * 131 + s1[i];
			b2[i] = b2[i - 1] * 131 + s2[i];
		}
		for (int i = 0;i <= n;i ++) {
			if (s1[i] != s2[i]) break;
			for (int j = n + 1;j > i;j --) {
				if (s1[j] != s2[j]) break;
				int x = b1[j - 1] - b1[i + 1] * poww[j - i - 1];
				int y = b2[j - 1] - b2[i + 1] * poww[j - i - 1];
				cout << x << ' ' << y << '\n';
				if (m[x] == y) ans ++;
			}
		}
		cout << ans << '\n';
	}
	
	
	return 0;
} 
