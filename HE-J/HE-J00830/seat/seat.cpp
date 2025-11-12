#include<bits/stdc++.h>
using namespace std;
int n,m,a[11][11];
int main(){
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin>>a[i][j];
		}
	}
	int c = 0,r = 1,a1 = a[0][0];
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(a1 < a[i-1][j-1]){
				if(r == 1&&c % 2 == 0){
					c++;
					r = 1;
				}
				if(c % 2 != 0){
					r++;
		 		}
				if(r == n&&c % 2 != 0){
					c++;
					r = n;
				}
				if(c % 2 == 0){
					r--;
				}
			}
		}
	}
	cout<<c<<" "<<r<<endl;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	return 0;
}
