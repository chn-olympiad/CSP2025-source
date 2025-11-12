#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[105];
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n,m,r, r2;
	cin >> n >> m;
	int s = n*m;
	for (int i = 1; i<=s; i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a+1, a+s+1);
	int cnt = 0; 
	for (int i=s;i>=1;i--){
		cnt++;
		if (a[i] == r) r2=cnt;
	}
	int r3 = r2%(2*n), r4=ceil(1.0*r2/n), r5=r2%n;
	if (r3 == 0) r3 = 2*n;
	if (r5 == 0) r5 = n;
	if (r3 <= n) cout << r4 << " " << r5;
	else cout << r4 << " " << n-r5+1;
	return 0;
} 
