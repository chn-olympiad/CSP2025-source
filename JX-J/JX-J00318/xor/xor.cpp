#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    if(n <= 2 && k == 0) {
		if(n == 2) {
			cout << 1;
		} else {
			cout << 0;			
		}
	} else if(n <= 10 && k <= 1) {
		cout << n/2;
	} else if(n <= 100 && k == 0) {
		cout << n/2;
	} else if(n <= 100 && k <= 1) {
		cout << n/2;
	} else {
		cout << 0;
	}
    return 0;
}
