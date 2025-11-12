#include<bits/stdc++.h>
using namespace std;
int a[10];
long long s;
int main () {
	freopen ("number.in" , "r" , stdin);
	freopen ("number.out" , "w" , stdout);
	cin >> s;
	while (s) {
		a[s%10]++;
		s/=10;
	}
	for (int i=9 ; i>=0 ; i--) {
		for (int j=1 ; j<=a[i] ; j++) {
			cout << i;
		}
	}
	cout << endl;
	return 0;
}
