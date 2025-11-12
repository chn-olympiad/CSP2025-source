#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int score[100];
	for (int i = 0; i < n * m; i++) {
		cin >> score[i];
	}
	int r = score[0];
	int r_mc = 0;
	sort(score, score + n * m);
	for (int i = 0; i < n * m; i++) {
		//cout << score[i] << endl;
		if (score[i] == r) {
			r_mc = n * m - i;
			break;
		}
	}
	//cout << n << endl;
	//cout << r_mc << endl;
	if (r_mc / n == 0) {
		cout << n << " ";
		if (n % 2 == 0) {
			if(r_mc % n == 0){
				//cout << " a ";
				cout << 1;
			}else {
				//cout << " b ";
				cout << n - r_mc % n + 1;
			}
		}else {
			if(r_mc % n == 0){
				//cout << " c ";
				cout << n;
			}else {
				//cout << " d ";
				cout << r_mc % n;
			}
		}
	}else {
		cout << ceil(r_mc / (n * 1.0)) << " ";
		if ((int)(ceil(r_mc / (n * 1.0))) % 2 == 0) {
			if(r_mc % n == 0){
				//cout << " e ";
				cout << 1;
			}else {
				//cout << " f ";
				cout << n - r_mc % n + 1;
			}
		}else {
			if(r_mc % n == 0){
				//cout << " g ";
				cout << n;
			}else {
				cout << r_mc % n;
			}
		}
	}

	//cout << r_mc % n;
	
	return 0;
}