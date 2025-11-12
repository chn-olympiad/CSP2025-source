#include<bits/stdc++.h>
using namespace std;
int n, m, x, a, top = 1;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> x;
	for(int i = 1;i < n * m;i++){
		cin >> a;
		if(a > x)top++;
	}
	int a1 = ceil(top / 1.0 / n), a2 = (top - 1) % n + 1;
	if(a1 % 2 == 0)cout << a1 << ' ' << n - a2 + 1;
	else cout << a1 << ' ' << a2;
	return 0;
} 