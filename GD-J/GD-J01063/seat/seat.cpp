#include <bits/stdc++.h>
using namespace std;

const unsigned int Maxn = 100;
int L[Maxn];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, c, r, a;
	cin >> n >> m;
	int tot = n * m;
	for (int i = 0; i < tot; i++){
		cin >> L[i];
	}
	a = L[0];
	sort(L, L + n * m);
	for (int i = 0; i < tot; i++){
		if (L[i] == a) a = tot - i;
	}
	c = (a / n) + 1;
	if (c % 2 == 0) r = m - (a % n) + 1;
	else r = a % n;
	cout << c << " " << r << endl;
	return 0;
}
