#include<bits/stdc++.h>
using namespace std;
long long a[100][100], b[110];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c, r;
	cin >> n >> m;
	for(int i = 0; i <= n * m; i++){
		cin >> b[i];
			c = m-n+1;	
			r = n;
		}
	cout << c << ' ' << r;
	return 0;
}
