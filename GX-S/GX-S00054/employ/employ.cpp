#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;
int n, m, c[505], a[505];
long long ans = 1;
string s;

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
	}
	for(int i = 2; i <= n + 1; i++){
		ans = (ans * i) % mod;
	}
	printf("%lld", ans);
	return 0;
}
