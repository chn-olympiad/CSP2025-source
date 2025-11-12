#include <bits/stdc++.h>
using namespace std;
int a[10000];
int m[1000][1000];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m1;
	cin >> n >> m1;
	for(int i = 1;i <= n * m1;i++){
		cin >> a[i];
	}
	int ans = a[1];
	sort(a + 1, a + n * m1 + 1, greater<int>());
	int i = 1, j = 1;
	int cnt = 0;
	int base = 1;
	while(true){
		m[i][j] = a[++cnt];
		if(i == n && (n % 2 == 0 ? j == 1 : j == n)){
			break;
		}
		if(j + base <= n && j + base > 0){
			j += base;
		}else{
			if(j + base > n){
				base = -1;
				i++;
			}else if(j + base <= 0){
				base = 1;
				i++;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1; j <= m1; j++){
			if(m[i][j] == ans){
				cout << i << " " << j << endl;
				break; 
			}
		}
	}
	return 0;
} 
