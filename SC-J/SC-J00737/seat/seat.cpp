#include<bits/stdc++.h>
using namespace std;
int n, m;
int b[105];
int c, r, p, s;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++){
	 	cin >> b[i];
	}
	s = b[1];
	
	sort(b + 1, b + n * m + 1);
	cout << 1;
	for(int i = n * m; i > 1; i++){
		if(b[i] == s){
			p = i;
		}
	}
	
	while(p - 2 * n > 0){
		p - 2 * n;
		c += 2;
	}
	if(p > n){
		p -= n;
		c += 1;
	}
	r = p;
	cout << c << " " << r;
	return 0;
}