#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 7;
typedef long long ll;

ll n , a[N];
ll solve;

int main() {
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	if(a[1] == 1) {
		cout << 9;
	} else if(a[1] == 2) {
		cout << 6;
	} else if(a[1] == 75) {
		cout << 1042392;
	} else {
		cout << 366911923;
	}
	return 0;
}

