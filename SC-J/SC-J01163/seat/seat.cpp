#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
int n, m, sc[N], r, now;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout); 
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> sc[i];
	r = sc[1];
	sort(sc + 1, sc + n * m + 1, greater<int>());
	for(int i = 1; i <= n * m; i++) {
		if(sc[i] == r) {
			r = i;
			break;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(i % 2 == 1) {//从前往后 
			for(int j = 1; j <= m; j++) {
				now++;
				if(now == r) {
					cout << i << " " << j << endl;
					return 0;
				}
			}
		} else { //从后往前 
			for(int j = m; j >= 1; j--) {
				now++;
				if(now == r) {
					cout << i << " " << j << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
