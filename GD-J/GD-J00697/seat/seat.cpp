#include<bits/stdc++.h>
using namespace std;

int n, m, k = 1, r, a[110], mat[20][20];

bool cmp(int x, int y){
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m; // n为行数，m为列数
	for(int i = 1; i <= n * m; i ++){
		cin >> a[i];
	}
	r = a[1]; 
	sort(a+1, a+1+n*m, cmp);
	for(int i = 1; i <= m; i += 2){
		for(int j = 1; j <= n; j ++){
			if(a[j] == r) {
				cout << i << ' ' << j;
				return 0;
			}
			mat[j][i] = a[k];
			k ++;
		}
		for(int j = n; j >= 1; j --){
			if(a[k] == r) {
				cout << i+1 << ' ' << j;
				return 0;
			}
			mat[j][i+1] = a[k];
			k ++;
		}
	}
	for(int i = 1; i <= m; i ++){
		for(int j = 1; j <= n; j ++){
			if(mat[i][j] == r)
				cout << j << ' ' << i;;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
