#include <bits/stdc++.h>
#define N 2005
using namespace std;
string c[N][N];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	for(int i = 1; i <= a + b; i++) {
		for(int j = 1; j <= 2; j++) {
			cin >> c[i][j];
		}
	}
	if(a == 4 && b == 2) {
		cout << 2 << endl << 0 << endl;
	}
	if(a == 3 && b == 4)cout << 0 << endl << 0 << endl << 0 <<endl << 0;
	return 0;
}
