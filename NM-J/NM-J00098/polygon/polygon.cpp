#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10000;
int a[MAXN];

int main() {
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    int n;
    cin >> n;
    if (n < 3) {
    	cout << "0";
    	return 0;
	}
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
	}
	if (a[0] + a[1] > a[2] && a[1] + a[2] > a[0] && a[0] + a[2] > a[1]) {
		cout << "1";
	} else {
		cout << "0";
	}
    return  0;
}
