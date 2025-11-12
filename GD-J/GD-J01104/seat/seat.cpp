#include<bits/stdc++.h>
using namespace std;
int a[400];
int b[20][20], c[20][20];
bool cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	int k = a[1];
//	sort(a + 1, a + n * m + 1, cmp);
//	for(int i = 1; i <= n * m; i++){
//		cout << a[i] << " ";
//	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			c[i][j] = a[(i - 1) * n + j];
		}
	}	
//	for(int i = 1; i <= m; i++){
//		for(int j = 1; j <= n; j++){
//			cout << c[i][j] << " ";
//		}
//		cout << endl;
//	}	
	for(int j = 1; j <= m; j++){
		if(j % 2 == 1){
			for(int i = 1; i <= n; i++){
				b[i][j] = c[j][i];
			}
		} else {
			for(int i = n; i >= 1; i--){
				b[i][j] = c[j][n - i + 1];
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(b[i][j] == k)
				cout << i << " " << j;
//			cout << b[i][j] << " ";
		}
//		cout << endl;
	}
	return 0;	
}
