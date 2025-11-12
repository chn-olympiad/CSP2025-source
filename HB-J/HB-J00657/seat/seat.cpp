#include <bits/stdc++.h>
using namespace std;
int main(){
	feopen("seat.in","r",stdin);
	feopen("seat.out ,"w",stdout);
	int n , m;
	cin >> n >> m;
	int a[n][m];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(a[i][j] <= a[i][j+1]){
				int t;
				t = a[i][j];
				a[i][j] = a[i][j+1];
				a[i][j+1] = t;
			}
		}
	}
	cout << a[n][m];
	return 0;
}
