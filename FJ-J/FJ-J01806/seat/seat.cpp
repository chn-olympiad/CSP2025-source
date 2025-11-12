#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4 + 5;
int n, m, rc, ri;
int rn, rm, c[N];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> c[i];
	}
	rc = c[1];
	sort(c + 1, c + n*m + 1);
	for(int i = n*m;i >= 1;i--){
		ri++;
		if(c[i] == rc){
			break;
		}
	}
	rn = (ri - 1) / n + 1;
	if(rn % 2 == 1){
		rm = ri % n;
		if(rm == 0){
			rm = n;
		}
	}
	else{
		while(ri > n){
			ri -= n;
		}
		rm = n - ri + 1;
	}
	cout << rn << " " << rm;
	return 0;
}
