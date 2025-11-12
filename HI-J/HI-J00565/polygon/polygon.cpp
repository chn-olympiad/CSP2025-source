#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5, Q = 998244353;
int a[N];

int main (void){
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n;
	cin >> n;
	int xyd = -0x3f, cnt = 0, ans = 0;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		xyd = max(xyd, a[i]);
	}
	if (n <= 3){
		if (n < 3){
			cout << 0;
			return 0;
		} else if (a[1] + a[2] + a[3] <= xyd * 2){
			cout << 0;
			return 0;
		} else {
			cout << 1;
			return 0;
		}
	}
	return 0;
}
