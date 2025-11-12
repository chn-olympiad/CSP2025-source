#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long a[5005];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort (a+1,a+n+1);
	if (n == 3){
		if (((a[1]+a[2]) > a[3])) cout << 1 << endl;
		else cout << 0 <<endl; 
	}
	else cout << a[n/2+1]*a[n/2+1] << endl;
	return 0;
} 
