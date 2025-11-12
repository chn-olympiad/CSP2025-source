#include<bits/stdc++.h>
using namespace std;
int a[15][15], b[105];
bool cmp(int x, int y) {
	return x > y;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin>>n>>m>>b[0];
	int x = b[0];
	for (int i = 1; i < n * m; i++) {
		cin>>b[i];
	}
	sort(b, b + n * m, cmp);
	for (int i = 1, k = 0; i <= n; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j <= m; j++) {
				if (b[k] == x) {
					cout<<i<<" "<<j;
					return 0;
				}
				a[i][j] = b[k];
				k++;
			}
		}
		else {
			for (int j = m; j >= 1; j--) {
				if (b[k] == x) {
					cout<<i<<" "<<j;
					return 0;
				}
				a[i][j] = b[k];
				k++;
			}
		}
	}
	return 0;
} 
