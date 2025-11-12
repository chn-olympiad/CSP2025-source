#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 5e5 + 10, M = (1 << 20) + 10, V = (1 << 20);
int n, k, a[N], f[N], mx[M];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] ^= a[i-1];
	}
	for(int i = 0; i <= V; i++) mx[i] = -1;
	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= i; j++){
//			if((a[i] ^ a[j-1]) == k) f[i] = max(f[i], f[j-1] + 1);
//		}
		f[i] = max(f[i], max(f[i-1], mx[a[i]]+1));
		mx[a[i]^k] = max(mx[a[i]^k], f[i]);
	}
	cout << f[n];
	return 0;
}
