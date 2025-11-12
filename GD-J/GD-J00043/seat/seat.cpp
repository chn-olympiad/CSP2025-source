#include<bits/stdc++.h>
using namespace std;
int n, m, x, y, p=1;
int a[101];
int main(){
	fropen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>> n >> m;
	for(int i = 1; i <= m*n; i++){
		cin >> a[i];
		if(a[i] > a[1]) p++;
	}
	while(p >= 2*n){
		p -= 2*n;
		x += 2;
	}
	if(p) x++;
	else{
		cout << x << ' ' << 1;
		return 0;
	}
	if(p > n){
		p -= n;
		x++;
		y = m-p+1;
	}
	else y = p;
	cout<< x << ' ' << y;
	return 0;
}
