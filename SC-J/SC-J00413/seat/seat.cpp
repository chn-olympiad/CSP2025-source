#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	vector<long long> a;
	for(int i = 0, x; i < n * m; ++i){
		cin >> x;
		a.push_back(x);
	}
	int r = a[0];
	sort(a.begin(), a.end());
//	for(int i = 0; i < n * m; ++i) cout << a[i] << " ";
	int b[n][m];
	for(int i = 0, j = 0; i < m; i += 1) {
		if(!(i & 1)){
			for(; j < n; ++j){
				b[i][j] = a[a.size() - 1];
//				cout << "b[" << i << "][" << j << "] = " << b[i][j] << endl;
				a.pop_back();
			}
			j--;
		}
		else {
			for(; j >= 0; --j){
				b[i][j] = a[a.size() - 1];
//				cout << "b[" << i << "][" << j << "] = " << b[i][j] << endl;
				a.pop_back();
			}
			j++;
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j){
			if(r == b[i][j]) cout << i + 1 << " " << j + 1;
		}
	}
}