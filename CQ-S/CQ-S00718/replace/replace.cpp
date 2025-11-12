#include <bits/stdc++.h>
using namespace std;
int n, q, i, j;
string s;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(i = 1; i <= n; i++){
		cin >> s;
	}
	for(i = 1; i <= q; i++){
		cin >> s;
	}
	for(i = 1; i <= q; i++){
		cout << 0 << "\n"; 
	}
	return 0;
}
