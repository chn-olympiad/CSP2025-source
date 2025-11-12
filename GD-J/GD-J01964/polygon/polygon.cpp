#include<bits/stdc++.h>
using namespace std;
int n, a[5010];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
	}
	
	bool f = 1;
	for(int i=1; i<=n; i++) {
		if(a[i] != 1) {
			f = 0;
			break;
		}
	} if(f == 1){
		cout << (n-1) * (n-2) / 2 << endl;
	}
	
	return 0;
}
