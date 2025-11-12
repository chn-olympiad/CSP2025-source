#include <bits/stdc++.h>
using namespace std;
int n, q;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout); 
	srand((unsigned)time(0));
	cin >> n >> q;
	while(q--) {
		cout << rand()%n << endl; // 接下来就看 RP 了！ 
	}
	return 0;
} 
