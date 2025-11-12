#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int mod = 998244353;
int c[N];
int tong[N];
int sum[N];
int nu[N]; //not used 
int ct[N];//cut line

long long A(int m, int n){
	int ans = 1;
	for(int i = 0;i < m;i++){
		ans *= (n - i);
	}
	return ans;
}

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	} 
	long long ans = A(n, n);
	cout << ans % mod;
	return 0;
}