#include <bits/stdc++.h>
using namespace std;
int a[1100000];
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	int tot = 0;
	for (int i = 1; i <= n; i++){
		if (s[i] >= '0' && s[i] <= '9'){
			a[++tot] = s[i] - '0';
		}
	}
	sort(a + 1, a + tot + 1);
	for (int i = tot; i >= 1; i--){
		cout << a[i];
	}
	cout << '\n';
	return 0;
} 
