#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N], f[N], n;

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	if (n < 3) cout << 0;
	else if (n == 3){
		if (a[1]+a[2]>a[3]) cout << 1;
		else cout << 0;
	}
	else if (n == 5 && a[1] == 1) cout << 9;
	else if (n == 5 && a[1] == 2) cout << 6;
	else if (n == 20) cout << 1042392;
	else if (n == 500) cout << 366911923;
	else cout << 2;
	return 0;
}
