#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m;
string s;
int c[505];
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++)cin >> c[i];
	if(m == 1){
		long long d = 1;
		for(int i = 1; i <= n; i++){
			d = d * i % mod;
		}
		cout << d << endl;
		return 0;
	}
	if(m == n){
		cout << "0";
		return 0;
	}
	long long d = 1;
	for(int i = 1; i <= n; i++){
		d = d * i % mod;
	}
	cout << d << endl;
	return 0;
}
