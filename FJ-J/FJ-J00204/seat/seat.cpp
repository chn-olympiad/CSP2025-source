#include <bits/stdc++.h>
using namespace std;
int seat[15][15], a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i +=1){
		cin >> a[i];
	}
	int ar = a[1];
	for (int i = 1; i <= n*m; i ++){
		for(int j = 2; j <= n*m; j ++ ){
			if (a[j] > a[j-1]){
				int t = a[j-1];
				a[j-1]= a[j];
				a[j] = t;
			}
		}
	}
	if (n == 1 && m == 1) {
		cout << 1 << ' ' << 1;
		return 0;
	}
	for (int j = 1; j <= m; j ++){
		if (j % 2 == 1){
			for (int k  = 1; k <= n; k ++){
				seat[k][j] = a[k + (j-1)*n];
			}
		}
		else if (j % 2 == 0){
			int cnt = n;
			for (int k = 1; k <= n; k ++){
				seat[k][j] = a[cnt + (j-1)*n];
				cnt--;
			}
		}
	}
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= m; j ++){
			if (seat[i][j] == ar) {
				cout << j << ' ' << i;
				return 0;
			}
		}
	}
	return 0;	
}
