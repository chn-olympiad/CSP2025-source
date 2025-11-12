#include <bits/stdc++.h>
using namespace std;
int a[105];
int cmp(int x, int y){
	return x > y;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
	}
	int r = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1; i <= n*m; i++){
		int j = (i-1)/n;
		if(a[i] == r && (j+1) % 2 != 0){
			if(i % n == 0){
				cout << i/n << " " << n;
			}else{
				cout << i/n+1 << " " << n - ((i/n+1)*n - i);
			}
		}
		if(a[i] == r && (j+1)% 2 == 0){
			if(i % n == 0){
				cout << i/n << " " << 1;
			}else{
				cout << i/n+1 << " " << i - i/n;			
			}
		}
	}
	return 0;
}

