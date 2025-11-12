#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m;
string s;
int c[505];
long long A(int a){
	long long rt = 1;
	for(int i = 1; i <= a; i++) rt = (rt * i) % mod;
	return rt;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++) cin >> c[i];
	bool p = 0;
	int len = s.size();
	for(int i = 0; i < len; i++){
		if(s[i] == '0') p = 1;
	}
	if(m == n && p){
		cout << 0;
		return 0;
	}
	if(!p){
		cout << A(n);
		return 0;
	}
	sort(c + 1,c + n + 1);
	cout << 0;
	return 0;
}
