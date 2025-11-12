#include <bits/stdc++.h>
using namespace std;

int n, m, t;
int a[1003];
int seats[15][15], posc = 1, posl = 1, dirc = 1, sums = 1;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) cin >> a[i];
	t = a[1];
	sort(a + 1, a + n * m + 1);
	sums = n * m;
	while (sums >= 1) {
		if (a[sums] == t) {
			cout << posl << " " << posc << endl;
			return 0;
		}
		if ((posc >= n && dirc == 1) || (posc <= 1 && dirc == -1)) posl++, dirc *= -1;
		else posc += dirc;
		sums--;
	}
	
	return 0;
} 