#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a, t, cnt = 0;
	cin >> a;
	for(int i = 2; i <= n * m; i++) {
		cin >> t;
		if(t > a) {
			cnt++;
		}
	}
	cnt += 1;
	int ansn, ansm;
	ansn = ansm = 0;
	ansm = (cnt + n - 1) / n;
	if(ansm % 2 == 0) {
		if(cnt % n != 0) {	
			ansn = n - cnt % n + 1;
		} else {
			ansn = n;
		}
	} else { 
		if(cnt % n != 0) {
			ansn = cnt % n;
		} else {
			ansn = n;
		}
	}
	cout << ansm << " " << ansn << endl;
	return 0;
}
//	freoepn("seat.in", "r", stdin);
//	freopen("seat.out", "w", stdout);
// this biSai AKed me! 
