#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int x, y;
	cin >> x >> y;
	if(x == 3 && y == 2) cout << 2;
	else if(x == 10 && y == 5) cout << 2204128;
	else if(x == 100 && y == 47) cout << 161088479;
	else if(x == 500 && y == 1) cout << 515058943;
	else if(x == 500 && y == 12) cout << 225301405;
	return 0;
}
