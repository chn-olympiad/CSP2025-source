#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("r","seat.in",stdin);
	freopen("w","seat.out",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int k = a[1];
	int dx;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i] == k){
			dx = n*m-i+1;
		}
	}
	for(int i=1;i<=n;i++){
		if(i % 2 == 1){
			for(int j = 1;j <= m;j++){
				dx--;
				if(dx == 0){
					cout << i << " " << j;
					return 0;
				}
			}
		}
		else{
			for(int j = m;j >= 1;j--){
				dx--;
				if(dx == 0){
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
}
