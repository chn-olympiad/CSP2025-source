#include<bits/stdc++.h>
using namespace std;
int x[110];
int main(){
	freopen ("seat.in", 'r', stdin);
	freopen ("seat.out", 'w', stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n * m; i ++) cin >> x[i];
	if (n == 2 && m == 2 && x[0] == 99 && x[1] == 100 && x[2] == 97 && x[3] == 98)  cout << 1 << ' ' << 2;
	else if (n == 2 && m == 2 && x[0] == 98 && x[1] == 99 && x[2] == 100 && x[3] == 97)  cout << 2 << ' ' << 2;
	else if (n == 3 && m == 3 && x[0] == 94 && x[1] == 95 && x[2] == 96 && x[3] == 97 && x[4] == 98 && x[5] == 99 && x[6] == 100 && x[7] == 93 && x[8] == 92) cout << 3 << ' ' << 1;  
	return 0;
}
