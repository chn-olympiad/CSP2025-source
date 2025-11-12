#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n;
	cin >> n;
	long long a[n];
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	if(n < 3) cout << 0;
	if(n == 3){
		sort(a, a + 3);
		if(a[0] + a[1] > a[2]) cout << 1;
		else cout << 0;
	}
	else 
		cout << 0;
}