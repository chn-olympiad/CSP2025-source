#include<bits/stdc++.h>
using namespace std;
int n , t , a[500010] , ans , s;
int main () {
	freopen ("xor.in" , "r" , stdin);
	freopen ("xor.out" , "w" , stdout);
	cin >> n >> t;
	for (int i=1 ; i<=n ; i++) {
		cin >> a[i];
		if (a[i]==t) {
			ans++;
		}
	}
	for (int i=1 ; i<=n ; i++) {
		for (int j=i+1 ; j<=n ; j++) {
			s=0;
			for (int k=i ; k<=j ; k++) {
				s=s^a[k];
			}
			if (s==t) {
				ans++;
			}
		}
	}
	cout << ans/2 << endl;
	return 0;
}
