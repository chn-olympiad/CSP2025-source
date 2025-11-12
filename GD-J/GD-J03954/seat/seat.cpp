#include <bits/stdc++.h>
using namespace std;
int a[15][15], b[106], n, m, a1, g[225];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m*n; i++){
			cin >> g[i];
	}
	a1 = g[1];
	sort(g+1, g+1+n*m);
	for (int i = 1; i <= n*m; i++){
		
		if (g[i] == a1){
			cout << (i-1)%n+1<<' ';
			if(i%(2*n) < n) cout << i%(2*n);
		    else cout << n-i%(2*n)-1;
		}
	}
} 
