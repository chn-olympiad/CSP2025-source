#include<bits/stdc++.h>
using namespace std;
int t;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--) {
		int n, a[10010][10] = {0};
	  	cin >> n;
	  	const int m = n / 2;
	  	int c[10];
	  	c[1] = m;
	  	c[2] = m;
	  	c[3] = m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		int f = 0;
		for (int i = 1; i <= n; i++) {
			for (int o = 1; o <= 3;o++){
				for (int j = 1; j < 3; j++ ){
					if(a[i][j + 1] > a[i][j]) swap(a[i][j +1], a[i][j]);
				}
			}
			if(c[1] != 0) {
				f += a[i][1];
				
			}else if(c[2] != 0){
				f += a[i][2];
				
			} else if(c[3] != 0){
				f += a[i][3];
				
			}
		}
		cout << f << endl;
	}
	return 0;
} 
