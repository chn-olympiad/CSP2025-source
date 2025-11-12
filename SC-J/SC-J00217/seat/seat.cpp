#include<bits/stdc++.h>
using namespace std;
int n, m, t, a[200];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++)
		cin >> a[i];
	int p = a[1];
	sort(a+1, a+n*m+1);
	for (int i = n*m; i >= 1; i--){
		if (a[i] != p) t++;
		else{t++; break;}
	}
	int x=1, y=0, z=0, q=0;
	for (int i = 1; i <= n*m; i++){
		z++, q++;
		if (q == t && z > n) break;
		if (z <= n) y++;
		else y--;
		if (q == t && z <= n) break;
		if (z == n){x++;}
		if (z == 2*n) {z=0, x++;}
	}
	cout << x << " " << y;
	return 0;
}