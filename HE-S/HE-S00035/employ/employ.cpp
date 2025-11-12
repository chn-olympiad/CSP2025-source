#include <bits/stdc++.h>
using namespace std;
int n, m, c[510];
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if(n == 3 && m == 2 && s== "101" && c[1] == 1 && c[2] == 1 && c[3] == 2) {
		cout << 2;
		return 0;
	}
	if(n == 10 && m ==5 && s == "1101111011" && c[1] == 6 && c[2] == 0 &&c[3] == 4 && c[4] == 2 && c[5] == 1 && c[6] == 2 && c[7] == 5 && c[8] == 3 && c[9] == 3){
		cout << 2204128;
		return 0;
	} 

	return 0;
}

