#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100][100],u,b[100][100],r,c;
	cin >> n >> m;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) cin >> a[i][j];
	u = a[0][0];
	for(int i = 1; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j - 1] < a[i][j]){
				swap(a[i][j],a[i][j - 1]);
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0 ;j < m; j++){
			if(u == a[i][j]){
				c = i + 1;
			}
			r = i + 1;
		}
	}
	cout << c << ' ' << r;
	return 0;
}

