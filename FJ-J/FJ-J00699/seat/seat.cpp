#include<bits/stdc++.h>
using namespace std;
int a[5000];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, cnt=0;
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++){
		cin >> a[i];
		if(a[i] > a[1]) cnt++;
	}
	bool flag = 0;
	int dx=1, dy=1;
	for(int i = 1; i <= cnt; i++){
		if(flag == 0){
			dx++;
			if(dx > n){
				dx--;
				dy++;
				flag = 1;
			}
		}else{
			dx--;
			if(dx < 1){
				dx++;
				dy++;
				flag = 0; 
			}
		}
	}
	cout << dy << " " << dx;
	return 0;
}
