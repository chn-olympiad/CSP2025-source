#include<bits/stdc++.h>
using namespace std;

int n, m, a[105];
int rj, rm;

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i < n*m;i++){
		cin >> a[i];
	}rj = a[0];
	sort(0+a, a+n*m);
	for(int i = n*m-1;i >= 0;i--){
		if(a[i] == rj){
			rm = n*m-i;
		}
	}if(rm % n == 0){
		cout << rm/n << " " << n;
	}else{
		if((rm/n+1) % 2 == 0){
			cout << rm/n+1 << " " << n-rm%n+1;
		}else{
			cout << rm/n+1 << " " << rm%n; 
		}
	}
	return 0;
}
