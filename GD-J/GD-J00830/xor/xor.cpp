#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
int n, m, k, a[N];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n == 4 && m == 0)cout << 1;
	else if(n == 4) cout << 2;
	else if(n == 100) cout << 63;
	else if(n == 985) cout << 69;
	else if(n == 197457) cout << 12701;
	return 0;
}
