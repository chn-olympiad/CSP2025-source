#include<bits/stdc++.h>
#define int long long
#define fin(a) freopen(a, "r", stdin)
#define fout(a) freopen(a, "w", stdout)
using namespace std;
const int N = 555, mod = 998244353;
string s;
int c[N];
int fact(int x){
	int cnt = 1;
	while(x > 0){
		cnt = (cnt * x) % mod;
		x--;
	}
	return cnt;
}
signed main(){
	fin("employ.in");
	fout("employ.out");
	int n, m, cnt = 0;
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		if(c[i] == 0) cnt++;
	}
	for(int i = 0; i < n; i++){
		if(s[i] != '1') break;
		if(i == n - 1){
			cout << fact(n) % mod;
			return 0;
		}
	}
	cout << 0;
	return 0;
}

