#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,xr,rs;
	int wz[100][100];
	cin >> n >> m;
	int a[n*m];
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	xr = a[1];
	rs = n*m;
	sort(a+1,a+n*m+1);
	for(int i = 1;i <= m;i++){
		if(i % 2 != 0){
			for(int j = 1;j <= n;j++){
				wz[i][j] = a[rs];
				if(a[rs] == xr){
					cout << i << ' ' << j;
				}
				rs--;  
			}
		}
		else if(i % 2 == 0){
			for(int j1 = n;j1 >= 1;j1--){
				wz[i][j1] = a[rs];
				if(a[rs] == xr){
					cout << i << ' ' << j1;
				}
				rs--;
			}
		}
	}
	return 0;
} 
