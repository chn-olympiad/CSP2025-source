#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n , m , l = 0;
	cin >> n >> m;
	int t;
	cin >> t;
	for(int i = 2; i <= n * m; i++){
		int a;
		cin >> a;
		if (t < a) l++ ;
	}
	int x = l/n + 1, y;
	if(x % 2 == 1) y = l%n + 1;
	else y = m - l%n;
	cout << x << " " << y;
} 
