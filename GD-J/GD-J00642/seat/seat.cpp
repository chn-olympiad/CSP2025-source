#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a;
	cin >> n >> m >> a;
	int cnt;
	for(int i = 1; i < m * n; i++){
		int t;
		cin >> t;
		if(t > a) cnt++;
	}
	int rw = 1, cl = 1;
	int ta = cnt / (m * 2);
	if(ta > 0){
		cnt %= (m * 2);
		cl += ta * 2;
	}
	
	if(cnt / m > 0){
		cnt %= m;
		cl += 1;
		rw = n;
	}
	
	if(rw == 1) rw += cnt;
	else if(rw == n) rw -= cnt;
	cout << cl  << " "<< rw;
	return 0;
}
