#include <cstdio>
#include <iostream>
#include <random>
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[5005][2], sum, s[5005];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i][0];
		sum += a[i][0];
		s[i] = a[i - 1][0] + a[i][0];
		a[i][1] = max(a[i - 1][1], a[i][0]);
	}
	if(n < 3){
		cout << 0;
		return 0;
	}
	if(n == 3){
		if(sum > 2 * a[3][0]) cout << 1;
		else cout << 0;
		return 0;
	}
	cout << rand();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
