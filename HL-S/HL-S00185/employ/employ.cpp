#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int a[520];
int c[520];
//我还以为六点走 还摸了一会鱼 然后发现是半点 火速来骗一个 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	int n , m;
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		char ch;
		cin >> ch;
		a[i] = ch - '0'; 
	}
	for(int i = 1;i <= m;i ++) cin >> c[i];
	int ans = 0;
	for(int i = 1;i <= m;i ++) if(c[i] > 0) ans ++;
	long long tans = 0;
	for(int i = m;i <= ans;i ++){
		long long cnt = 1;
		for(int j = 2;j <= m;j ++){
			cnt *= j;
			cnt %= mod;
		}
		tans += cnt;
		tans %= mod;
	}
	cout << tans;
	return 0;
} 
