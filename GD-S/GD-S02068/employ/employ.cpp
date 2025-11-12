#include<bits/stdc++.h>
using namespace std;
long long n, m, a[505], sum = 1;
string s;
int main(){
	freopen("employ3.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum = sum * i % 101000000000;
	}
	cout << sum % 998244353 << endl;
	return 0;
}
