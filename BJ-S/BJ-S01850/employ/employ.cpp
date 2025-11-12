#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, jie = 1;
int  main(){ 
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
			jie *= i;
			jie %= 998244353;
	}
	cout << jie;
	

}