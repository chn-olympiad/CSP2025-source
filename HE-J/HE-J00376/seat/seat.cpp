#include<bits/stdc++.h>
using namespace std;
int a[105], n, m, l, s[105][105], k;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n*m; i++) {
		cin >> a[i];
	}
	l = a[1];
	sort(a, a+n);
	for (int i = 1; i <= n*m; i++) {
		if (a[i] <= a[i+1]){
			int t = a[i+1];
			a[i + 1] = a[i];
			a[i] = t;
		}
	}
	int o = 1;
	for (int i = 1; i <= n; i++){
		if (k == 0){
			for (int j = 1; j <= m; j++){
			s[i][j] = a[o];
			if (s[i][j] == l){
				cout << i << " " << j;
				return 0;
			}
			o++;
			
		}
		k = 1;
		} else{
			for (int j = m; j >= 1; j--){
			s[i][j] = a[o];
			if (s[i][j] == l){
				cout << i << " " << j;
				return 0;
			}
			o++;
		}
		k = 0;
		}
		
	}
} 
