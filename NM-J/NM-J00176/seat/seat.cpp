#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, r, a[105]={};
	cin >> n >> m;
	for (int i = 0; i < n*m; i++) cin >> a[i];
	r = a[0];
	sort(a, a+n*m, greater<int>());
	int pos;
	for (int i = 0; i < n*m; i++){
//		cout << a[i] << ' ';
//		if (i%n == n-1) cout << endl;
		if (a[i] == r) {
			pos = i;
//			cout <<endl;
			break; 
		}
	}
	int col = pos/n+1, ln=pos%n;
	if (col % 2 == 0) ln = n-ln-1;
	ln ++;
	cout << col << ' ' << ln;
	return 0;
} 
