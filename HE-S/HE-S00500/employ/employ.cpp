#include<bits/stdc++.h>
using namespace std;
int n, m;
int c[600];
const int mod = 998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	long long ans = 1;
	for(int i = n; i >= 2; i++){
		ans = (ans*i)%mod;
	}
	cout << mod;
	return 0;
} 
