// JS-J00236
// XD

#include<bits/stdc++.h>
using namespace std;
int n, m, id = 1, myscore, otherscore, c, r;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> myscore;
	for (int i = 1; i < n * m; ++i){
		cin >> otherscore;
		if (otherscore > myscore){
			++id;
		}
	}
	c = (id - 1) / n + 1;
	r = ((c % 2 == 0) ? (2 * n - id % (2 * n) + 1) : (id % (2 * n))) ;
	cout << c << " " << r;
	return 0;
}
