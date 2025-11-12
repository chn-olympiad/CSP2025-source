#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5000,mod = 998244353;

long long fnc[N + 5],ret = 0;
int arr[N + 5],n;

void dfs(int i,int su,int ma,int c) {
	if (i == n + 1) {
		if (c >= 3 && su > ma * 2) {
			ret = (ret + 1) % mod;
		}
		return ;
	}
	
	dfs(i + 1,su + arr[i],max(ma,arr[i]),c + 1);
	dfs(i + 1,su,ma,c);
	return ;
}

void init(int n) {
	fnc[0] = 1;
	for (int i = 1;i <= n;i++) {
		fnc[i] = fnc[i - 1] * i % mod;
	}
	
	return ;
}

long long fast_pow(long long a,long long b) {
	if (b == 0) {
		return 1;
	}
	long long ret = fast_pow(a,(b >> 1));
	if (b & 1) {
		return ret * ret % mod * a % mod;
	}
	return ret * ret % mod;
}

long long inv(long long x) {
	return fast_pow(x,mod - 2);
}

long long C(int n,int m) {
	return fnc[n] * inv(fnc[m] * fnc[n - m] % mod);
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int maxn = 0;
	cin >> n;
	
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
		
		maxn = max(maxn,arr[i]);
	}
	
	if (maxn == 1) {
		init(n);
		for (int i = 3;i <= n;i++) {
			ret = (ret + C(n,i)) % mod;
		}
		
		cout << ret << endl;
		return 0;
	}
	
	dfs(1,0,0,0);
	
	cout << ret << endl;
	return 0;
}
