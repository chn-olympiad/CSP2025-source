#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, s, x = 1, y;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a;
	for(int i = 1; i < n * m; i++){
		cin >> b;
		if(b > a) s++;
	}
	x += s / n;
	s %= n;
	if(x % 2) y = s + 1;
	else y = n - s;
	cout << x << " " << y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}