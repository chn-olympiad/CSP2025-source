#include<bits/stdc++.h>
using namespace std;
int n, m, r, x, num = 1;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> r;
	for(int i = 1 ; i < n * m ; i++) {
		cin >> x;
		if(x > r) num++;
	}
	if(num % n == 0) {
		cout << num / n << ' ';
		if((num / n) % 2 == 0) cout << 1;
		else cout << n;
	}
	else if((num / n) % 2 == 0) {
		cout << num / n + 1 << ' ' << num % n;
	}
	else cout << num / n + 1 << ' ' << n - num % n + 1;
	return 0;
}

