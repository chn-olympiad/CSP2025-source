#include <bits/stdc++.h>

using namespace std;
string s;
int a[1000005];
int t;
signed main(){
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	int len = s.size();
	for (int i = 0; i <	len; ++ i){
		if (isdigit(s[i])) a[++ t] = s[i] - '0';
 	}
 	sort (a + 1, a + 1 + t);
 	for (int i = t; i >= 1; i--) cout << a[i];
 	cout << "\n";
	return 0;
}
