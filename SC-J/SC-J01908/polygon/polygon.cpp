#include <bits/stdc++.h>
using namespace std;
int a[5];
int n, Cnt=0;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	cin >> a[1] >> a[2] >> a[3];
	sort(a+1, a+1+n);
	if(a[1]+a[2]+a[3]>2*a[3]) cout << 1;
	else cout << 0;
	return 0; 
}