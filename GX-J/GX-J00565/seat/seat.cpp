#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int mmap[11][11];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int r = 0;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a+1, a+1+n*m, cmp);
	int q = 1;
	int sum = 1;
	for(int i = 1; i <= m; i++){
		if(q % 2 != 0){
			for(int j = 1; j <= n; j++){
				mmap[j][i] = a[sum];
				sum++;
			}
		}else{
			for(int j = n; j >= 1; j--){
				mmap[j][i] = a[sum];
				sum++;
			}
		}
		q++;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(mmap[i][j] == r){
				cout << j << ' ' << i;
			}
		}
	}
		
	return 0;
}
	
