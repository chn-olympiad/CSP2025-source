#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.ans","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[11][11] = {};
	int b[11][11] = {};
	int c = a[1][1];
	a[0][0] = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int s = 1;s <= m;s++){
			cin >> a[i][s];
		}
	}
	for(int q = 0;q < n*m;q++){
		for(int j = 1;j <= n;j++){
			if(j % 2 != 0){
				for(int t = 1;t <= m;t++){
					if(a[j][t] > a[j][t-1]){
						b[j][t-1] = a[j][t-1];
						a[j][t-1] = a[j][t];
						a[j][t] = b[j][t-1];
					}	
				}
			}
			else{
				for(int g = m;g >= 1;g--){
					if(a[j][g-1] > a[j][g]){
						b[j][g] = a[j][g];
						a[j][g] = a[j][g-1];
						a[j][g-1] = b[j][g];
					}
				}
			} 
		}
	}
	for(int h = 0;h <= n;h++){
		for(int k = 0;k <= m;k++){
			if(a[h][k] == c){
				cout << h << k;
			}
		}
	}
	return 0;
}
