#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353; 
int n, ans, a[5005];
long long p[5005];
void dfs(int cur, int suma, int maxa, int gs){
	if(cur == n + 1){
		if(gs < 3) return;
		if(suma > maxa * 2) ans = (ans + 1) % mod;
		return;
	}
	dfs(cur + 1, suma + a[cur], max(maxa, a[cur]), gs + 1);
	dfs(cur + 1, suma, maxa, gs);
}

long long mypow(int a, int b, int p){
	if(b == 0) return 1;
	long long tmp = mypow(a, b / 2, p);
	if(b % 2) return tmp * tmp % p * a % p;
	else return tmp * tmp % p;
}

long long c(int n, int m){
	return p[n] * mypow(p[m], mod - 2, mod) % mod * mypow(p[n - m], mod - 2, mod) % mod;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	p[1] = 1;
	for(int i = 2; i <= 5000; i++) p[i] = p[i - 1] * i % mod;
	cin >> n;
	int maxna = -1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		maxna  = max(maxna, a[i]);
	} 
	if(maxna == 1){
		for(int i = 3; i <= n; i++){
			ans = (ans + c(n, i)) % mod;
		}
	}
	else{
		dfs(1, 0, -1, 0);
	}
	cout << ans << "\n";
	return 0;
}
