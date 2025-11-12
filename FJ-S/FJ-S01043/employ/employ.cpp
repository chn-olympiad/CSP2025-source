#include<bits/stdc++.h>

using namespace std;

int main(){
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	long long n;
	cin>> n;
	
	long long p = 998244353;
	long long ans = 1;
	for(int i = 2; i <= n; i++){
		ans *= i;
		ans %= p;
	}
	
	cout<< ans;
	
	return 0;
} 
