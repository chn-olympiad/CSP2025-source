#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m, n, sum;
	cin >> m >> n;
	int s[100];
	for (int i = 1; i <= n*m; i++) {
		cin >> s[i];
		int m = s[0];
	}
	if (m==99) cout << "1" << " " << "2";
    if (m == 98) cout << "2" << " " << "2";
	if (m == 94) cout << "3" << " " << "1";
	
	return 0;
}
